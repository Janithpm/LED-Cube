void setLayerP() {
  for (int i = 2; i < 4; i++) {
    clearCube();
    setLayer(i, 0);
    delay(100);
  }
  for (int i = 2; i < 4; i++) {
    clearCube();
    setLayer(i, 3);
    delay(100);
  }
}

void runRandom() {
  clearCube();
  for (int x = 0; x < 150; x++) {
    setCubeValue(random(4), random(4), random(4), 1);
    delay(4);
  }
  for (int x = 0; x < 150; x++) {
    setCubeValue(random(4), random(4), random(4), 0);
    delay(4);
  }
}
