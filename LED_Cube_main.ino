#include <TimerOne.h>
#define cubesize 4
#define push_button_pin 6
int SER_Pin = 8;
int RCLK_Pin = 9;
int SRCLK_Pin = 10;
boolean registers[16];
int layers[] = {2, 3, 4, 5};
boolean cube[cubesize][cubesize][cubesize];
int start_cmd = 0;
boolean cube_on = false;

void setup() {
  Serial.begin(9600);
  Timer1.initialize(3000);
  Timer1.attachInterrupt(drawCube);
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);
  writeRegisters();
  for (int z = 0; z < cubesize; z++) {
    pinMode(layers[z], OUTPUT);
  }
  clearCube();
}

void lightup_cube() {
  runLayers();
  runExpand();
  runRain(); runRain(); runRain(); runRain(); runRain();
  setLayerP(); setLayerP(); setLayerP();; setLayerP(); setLayerP();
  runRandom(); runRandom(); runRandom(); runRandom(); runRandom();
}

void loop() {
  start_cmd = digitalRead(push_button_pin);
  if (start_cmd == 1 && time_counter(2000) && !cube_on) {
    cube_on = true;
  }
  if (cube_on) {
    lightup_cube();
  }
  if (cube_on && start_cmd == 1) {
    clearCube();
  }
}
