#define lpat 5
int layer_patts[lpat][3] = {{1}, {2}, {3}, {1, 2}, {2, 3}};

void runLayers() {
  for (int p = 0; p < lpat; p++) {
    for (int z = 0; z < cubesize; z++) {
      clearCube();
      for (int pl = 0; pl < 3; pl++) {
        setLayer(layer_patts[p][pl], z);
      }
      delay(150);
    }
    for (int z = cubesize - 2; z > 0; z--) {
      clearCube();
      for (int pl = 0; pl < 3; pl++) {
        setLayer(layer_patts[p][pl], z);
      }
      delay(150);
    }
  }
}

void setLayer(int l, int z) {
  for (int x = 0; x < cubesize; x++) {
    for (int y = 0; y < cubesize; y++) {
      if (l == 1) {
        cube[z][x][y] = 1;
      } else if (l == 2) {
        cube[x][z][y] = 1;
      } else if (l == 3) {
        cube[y][x][z] = 1;
      }
    }
  }
}
