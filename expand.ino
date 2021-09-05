void runExpand() {

  for (int p = 0; p < 4; p++) {
    for (int i = 0; i < cubesize + 1; i++) {
      clearCube();
      if (p == 0) {
        drawCubeP(0, 0, 0, i);
      } else if (p == 1) {
        drawCubeP(0, cubesize - i, 0, i);
      } else if (p == 2) {
        drawCubeP(0, 0, cubesize - i, i);
      } else if (p == 3) {
        drawCubeP(0, cubesize - i, cubesize - i, i);
      }
      delay(100);
    }
    for (int i = cubesize - 1; i > 0; i--) {
      clearCube();
      if (p == 0) {
        drawCubeP(0, 0, 0, i);
      } else if (p == 1) {
        drawCubeP(0, cubesize - i, 0, i);
      } else if (p == 2) {
        drawCubeP(0, 0, cubesize - i, i);
      } else if (p == 3) {
        drawCubeP(0, cubesize - i, cubesize - i, i);
      }
      delay(100);
    }
  }
}

void drawCubeP(int pz, int px, int py, int s) {

  for (int z = pz; z < pz + s; z++) {
    for (int x = px; x < px + s; x++) {
      for (int y = py; y < py + s; y++) {
        if (1) {
          setCubeValue(z, x, y, 1);
        }
      }
    }
  }
}
