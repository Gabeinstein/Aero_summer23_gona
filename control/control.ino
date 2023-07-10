#include "wing.h"

Wing ala = Wing(9,10,11);  //Pines Servo

unsigned long *time_interval = new unsigned long[3];
unsigned long actual_time = 0;

void setup() {
  //Serial start
  Serial.begin(115200);

  //Attach de motores
  ala.set_servos();

  //Pins
  ala.set_pot_pin(A0,A1,A2);
  ala.set_RGB_pin(3,5,6);
  ala.set_button_pin(2);

  //Time
  for (int i = 0; i < 3; i++){
    time_interval[i] = millis();
  }

}

void loop() {
  actual_time = millis();

  //Motor position -> 10ms
  if ((actual_time - time_interval[0]) > 10){
    ala.update_motor_values();
    time_interval[0] = millis();
  }
  //Button State
  if ((actual_time - time_interval[1]) > 50){
    ala.read_button();
    time_interval[1] = millis();
  }
  // RED Blink
  if ((actual_time - time_interval[2]) > 1000){
    if ((actual_time - time_interval[2]) > 1100){
      ala.RGB_print(255,255,255); //Off inverse logic
      time_interval[2] = millis();
    }else{
      ala.RGB_print(0,255,255);
    }
  }
}
