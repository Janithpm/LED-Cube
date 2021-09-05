#define rain_count 16
int rain[rain_count][3];
int rainc[rain_count];

void initRain1() {
  int r = 0;
  for (int x = 0; x < cubesize; x++) {
    for (int y = 0; y < cubesize; y++) {
      rain[r][0] = 3;
      rain[r][1] = x;
      rain[r][2] = y;
      rainc[r] = random(15);
      r++;
    }
  }
}

void initRain2() {
  int r = 0;
  for (int x = 0; x < cubesize; x++) {
    for (int y = 0; y < cubesize; y++) {
      rain[r][0] = 0;
      rain[r][1] = x;
      rain[r][2] = y;
      rainc[r] = random(15);
      r++;
    }
  }
}

void runRain() {
  initRain1();
  boolean rn = true;
  while (rn) {
    int lc = 0;
    clearCube();
    for (int r = 0; r < rain_count; r++) {
      if (rainc[r] == 0) {
        if (rain[r][0] > 0) {
          rain[r][0]--;
        } else {
          lc++;
        }
      } else {
        rainc[r]--;
      }
      setCubeValue(rain[r][0], rain[r][1], rain[r][2], 1);
    }
    delay(100 - (lc * 5));
    rn = lc != 16;
  }
  delay(500);
  if (time_counter(500)) {
    initRain2();
    rn = true;
    while (rn) {
      int lc = 0;
      clearCube();
      for (int r = 0; r < rain_count; r++) {
        if (rainc[r] == 0) {
          if (rain[r][0] < 3) {
            rain[r][0]++;
          } else {
            lc++;
          }
        } else {
          rainc[r]--;
        }
        setCubeValue(rain[r][0], rain[r][1], rain[r][2], 1);
      }
      delay(100 - (lc * 5));
      rn = lc != 16;
    }
    delay(500);
  }
}
