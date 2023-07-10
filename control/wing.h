#ifndef WING_H
#define WING_H
#include <Servo.h>

class Wing{
private:
  Servo *servos;
  int *servo_pins;
  int *servo_angle;

  int *pot_value;
  int *pot_pins;

  int button_state;
  int state;
  int button_pin;

  int *RGB_pins;
  int *RGB_value;
public:
  Wing();
  Wing(int,int,int);

  void set_servos();
  void set_pot_pin(int,int,int);
  void set_RGB_pin(int,int,int);
  void set_button_pin(int);

  void read_pot_value();
  void map_pot_values();
  void read_button();

  void RGB_print(int,int,int);
  void write_servos();
  void update_motor_values();

  int* get_servo_pins();
  int* get_pot_pins();
  int* get_pot_value();
};

#endif 