#include "wing.h"

Wing ala = Wing(11,10,9);  //Pines Servo

unsigned long *time_interval = new unsigned long[4];
unsigned long actual_time = 0;
int last_button = 0;
bool buttonDown = false;
unsigned long hold_time = 0;

void setup() {
  //Serial start
  Serial.begin(115200);

  //Attach de motores
  ala.set_servos();

  //Pins
  ala.set_pot_pin(A0,A1,A2);
  ala.set_RGB_pin(3,5,6);
  ala.set_button_pin(2);
  ala.set_state(0);

  //Time
  for (int i = 0; i < 4; i++){
    time_interval[i] = millis();
  }
}

void loop() {
  actual_time = millis();
  button_state();
  states();
  //Serial.println(hold_time);
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
    // RED state
    ala.RGB_print(0,255,255);
    ala.set_angle(0,150,25);
    
  }else if(ala.get_state() == 2){
    // Green state
    ala.RGB_print(255,0,255);
    ala.set_angle(98,85,98);
  }else if(ala.get_state() == 3){
    // Blue state
    ala.RGB_print(255,255,0);
    ala.set_angle(72,85,76);
  }
}
void states(){
  //State Saves
  if (buttonDown == true && hold_time < ala.get_short_hold_time() && ala.get_state() != 0){
    buttonDown = false;
    ala.set_state(ala.get_state() + 1);
    if (ala.get_state() == 4){
      ala.set_state(1);
    }
  }else if (buttonDown == true && hold_time >= ala.get_long_hold_time()){ // Blink
    buttonDown = false;
    if(ala.get_state() != 0){
      ala.set_state(0);
    }else{
      ala.set_state(1);
    }
  }
}
void button_state(){
  //Button State
  if ((actual_time - time_interval[2]) > 50){
    last_button = ala.get_button_value();
    ala.set_button_value();
    time_interval[2] = millis();
    if (ala.get_button_value() != last_button){
      if (ala.get_button_value() == 1){
        time_interval[3] = millis();
        buttonDown = true;
      }else{
        buttonDown = false;
        hold_time = actual_time - time_interval[3];
      }
    }
  }
}
