#include "wing.h"

Wing ala = Wing(9,10,11);  //Pines Servo

unsigned long *time_interval = new unsigned long[4];
unsigned long actual_time = 0;
int last_button = 0;
bool buttonDown = false;

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
  for (int i = 0; i < 4; i++){
    time_interval[i] = millis();
  }

}

void loop() {
  actual_time = millis();
  if (ala.get_state() == 0){
    //Motor position -> 10ms
    if ((actual_time - time_interval[0]) > 10){
      ala.update_motor_values();
      time_interval[0] = millis();
    }
    // RED Blink
    if ((actual_time - time_interval[1]) > 1000){
      if ((actual_time - time_interval[1]) > 1100){
        ala.RGB_print(255,255,255); //Off inverse logic
        time_interval[1] = millis();
      }else{
        ala.RGB_print(0,255,255);
      }
    }
  }else if(ala.get_state() == 1){
    // RED Blink
    ala.RGB_print(255,255,0);
  }
  button_state();
}
void button_state(){
  //Button State
  if ((actual_time - time_interval[2]) > 50){
    ala.set_button_value();
    if (ala.get_button_value() != last_button){
      if (ala.get_button_value() == 1){
        time_interval[3] = millis();
        buttonDown = true;
      }else{
        buttonDown = false;
      }
    }
    time_interval[2] = millis();
  }

  last_button = ala.get_button_value();
  if (buttonDown == true && (actual_time - time_interval[3]) >= ala.get_long_hold_time()){
    buttonDown = false;
    if(ala.get_state() == 1){
      ala.set_state(0);
    }else{
      ala.set_state(1);
    }
  }
}
