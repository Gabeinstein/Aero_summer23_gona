#include "wing.h"

//Constructors
Wing::Wing(){
  servo_pins = new int[3];
  pot_value = new int[3];
  pot_pins = new int[3];
  servo_angle = new int[3];
  servos = new Servo[3];
  RGB_pins = new int[3];
  RGB_value = new int[3];
  long_hold = 1000;
  short_hold = 500;
}
Wing::Wing(int _aleron_servo_pin, int _slat_servo_pin, int _flap_servo_pin){
  servo_pins = new int[3];
  pot_value = new int[3];
  pot_pins = new int[3];
  servo_angle = new int[3];
  servos = new Servo[3];
  RGB_pins = new int[3];
  RGB_value = new int[3];
  long_hold = 1000;
  short_hold = 500;

  servo_pins[0] = _aleron_servo_pin;
  servo_pins[1] = _slat_servo_pin;
  servo_pins[2] = _flap_servo_pin;
}

//Servos
void Wing::set_servos(){
  servos[0].attach(servo_pins[0]);
  servos[1].attach(servo_pins[1]);
  servos[2].attach(servo_pins[2]);
}
void Wing::write_servos(){
  servos[0].write(servo_angle[0]);
  servos[1].write(servo_angle[1]);
  servos[2].write(servo_angle[2]);
}
void Wing::update_motor_values(){
  read_pot_value();
  map_pot_values();
  write_servos();
}
void Wing::set_angle(int _aleron, int _slat, int _flap){
  servo_angle[0] = _aleron;
  servo_angle[1] = _slat;
  servo_angle[2] = _flap;

  write_servos();
}
//Potentiometers
void Wing::set_pot_pin(int _aleron_pot_pin, int _slat_pot_pin, int _flap_pot_pin){
  pot_pins[0] = _aleron_pot_pin;
  pot_pins[1] = _slat_pot_pin;
  pot_pins[2] = _flap_pot_pin;
}
void Wing::read_pot_value(){
  pot_value[0] = analogRead(pot_pins[0]);
  pot_value[1] = analogRead(pot_pins[1]);
  pot_value[2] = analogRead(pot_pins[2]);
}
void Wing::map_pot_values(){
  servo_angle[0] = map(pot_value[0],0,1023,0,179);
  servo_angle[1] = map(pot_value[1],0,1023,0,179);
  servo_angle[2] = map(pot_value[2],0,1023,0,179);
}
int* Wing::get_pot_value(){
  return pot_value;
}

//Light
void Wing::set_RGB_pin(int _r_pin, int _g_pin, int _b_pin){
  RGB_pins[0] = _r_pin;
  RGB_pins[1] = _g_pin;
  RGB_pins[2] = _b_pin;

  pinMode(RGB_pins[0],OUTPUT);
  pinMode(RGB_pins[1],OUTPUT);
  pinMode(RGB_pins[2],OUTPUT);
}
void Wing::RGB_print(int _r, int _g, int _b){
  RGB_value[0] = _r;
  RGB_value[1] = _g;
  RGB_value[2] = _b;

  digitalWrite(RGB_pins[0],RGB_value[0]);
  digitalWrite(RGB_pins[1],RGB_value[1]);
  digitalWrite(RGB_pins[2],RGB_value[2]);
}

//Button
void Wing::set_button_pin(int _pin){
  button_pin = _pin;
  pinMode(button_pin,INPUT);
}
void Wing::set_button_value(){
  button_value = digitalRead(button_pin);
}
int Wing::get_button_value(){
  return button_value;
}
int Wing::get_long_hold_time(){
  return long_hold;
}
int Wing::get_short_hold_time(){
  return short_hold;
}
int Wing::get_state(){
  return state;
}
void Wing::set_state(int _state){
  state = _state;
}
