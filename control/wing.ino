#include "wing.h"

Wing::Wing(){
  servo_pins = new int[3];
  pot_value = new int[3];
  pot_pins = new int[3];
  servo_angle = new int[3];
  servos = new Servo[3];
  RGB_pins = new int[3];
  RGB_value = new int[3];
}
Wing::Wing(int _aleron_servo_pin, int _slat_servo_pin, int _flap_servo_pin){
  servo_pins = new int[3];
  pot_value = new int[3];
  pot_pins = new int[3];
  servo_angle = new int[3];
  servos = new Servo[3];
  RGB_pins = new int[3];
  RGB_value = new int[3];
  
  servo_pins[0] = _aleron_servo_pin;
  servo_pins[1] = _slat_servo_pin;
  servo_pins[2] = _flap_servo_pin;
}
void Wing::set_pot_pin(int _aleron_pot_pin, int _slat_pot_pin, int _flap_pot_pin){
  pot_pins[0] = _aleron_pot_pin;
  pot_pins[1] = _slat_pot_pin;
  pot_pins[2] = _flap_pot_pin;
}
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
void Wing::set_servos(){
  servos[0].attach(servo_pins[0]);
  servos[1].attach(servo_pins[1]);
  servos[2].attach(servo_pins[2]);
}
void Wing::set_button_pin(int _pin){
  button_pin = _pin;
  
  pinMode(button_pin,INPUT);
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
void Wing::read_button(){
  button_state = digitalRead(button_pin);
}
void Wing::update_motor_values(){
  read_pot_value();
  map_pot_values();
  write_servos();
}

void Wing::write_servos(){
  servos[0].write(servo_angle[0]);
  servos[1].write(servo_angle[1]);
  servos[2].write(servo_angle[2]);
}
int* Wing::get_servo_pins(){
  return servo_pins;
}
int* Wing::get_pot_value(){
  return pot_value;
}
int* Wing::get_pot_pins(){
  return pot_pins;
}