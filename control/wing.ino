#include "wing.h"

Wing::Wing(){
  servo_pins = new int[3];
  pot_value = new int[3];
  pot_pins = new int[3];
  servo_angle = new int[3];
}
Wing::Wing(int _aleron_servo_pin, int _slat_servo_pin, int _flap_servo_pin){
  servo_pins = new int[3];
  pot_value = new int[3];
  pot_pins = new int[3];
  servo_angle = new int[3];
  servo_pins[0] = _aleron_servo_pin;
  servo_pins[1] = _slat_servo_pin;
  servo_pins[2] = _flap_servo_pin;
}
void Wing::set_pot_pin(int _aleron_pot_pin, int _slat_pot_pin, int _flap_pot_pin){
  pot_pins[0] = _aleron_pot_pin;
  pot_pins[1] = _slat_pot_pin;
  pot_pins[2] = _flap_pot_pin;
}
void Wing::set_servos(){
  aleron.attach(servo_pins[0]);
  slat.attach(servo_pins[1]);
  flap.attach(servo_pins[2]);
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
void Wing::update_values(){
  read_pot_value();
  map_pot_values();
}
void Wing::write_servos(){
  aleron.write(servo_angle[0]);
  slat.write(servo_angle[1]);
  flap.write(servo_angle[2]);
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