#ifndef WING_H
#define WING_H
#include <Servo.h>

class Wing{
private:
  Servo aleron;
  Servo slat;
  Servo flap;
  int *pot_value;
  int *servo_pins;
  int *pot_pins;
  int *servo_angle;
public:
  Wing();
  Wing(int,int,int);
  void set_servos();
  void set_pot_pin(int,int,int);
  void read_pot_value();
  void map_pot_values();
  void write_servos();
  void update_values();
  int* get_servo_pins();
  int* get_pot_pins();
  int* get_pot_value();
};

#endif 