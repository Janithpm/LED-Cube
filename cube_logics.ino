void clearCube() {
  for (int z = 0; z < cubesize; z++) {
    for (int x = 0; x < cubesize; x++) {
      for (int y = 0; y < cubesize; y++) {
        cube[z][x][y] = 0;
      }
    }
  }
}

int drawing_layer = 0;
void drawCube() {
  writeRegisters();
  for (int z = 0; z < cubesize; z++) {
    if (drawing_layer == z) {
      digitalWrite(layers[z], LOW);
    } else {
      digitalWrite(layers[z], HIGH);
    }
  }
  drawing_layer++;
  if (drawing_layer == cubesize) {
    drawing_layer = 0;
  }
}

void writeRegisters() {
  digitalWrite(RCLK_Pin, LOW);
  for (int x = cubesize - 1; x > -1; x--) {
    for (int y = cubesize - 1; y > -1; y--) {
      digitalWrite(SRCLK_Pin, LOW);
      int val = cube[drawing_layer][x][y];
      if (x >= cubesize / 2) {
        val = cube[drawing_layer][5 - x][3 - y];
      }
      digitalWrite(SER_Pin, val);
      digitalWrite(SRCLK_Pin, HIGH);
    }
  }
  digitalWrite(RCLK_Pin, HIGH);
}

void setCubeValue(int z, int x, int y, int v) {
  if (z < cubesize && x < cubesize && y < cubesize && x > -1 && y > -1 && z > -1) {
    cube[z][x][y] = v;
  }
}

int last_time;
boolean time_saved = false;
boolean time_counter(int x) {
  if (!time_saved) {
    last_time = millis();
    time_saved = true;
  }
  if ((millis() - last_time) >= x) {
    time_saved = false;
    return true;
  }
  else {
    return false;
  }
}
