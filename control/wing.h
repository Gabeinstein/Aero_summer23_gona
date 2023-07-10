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

  int button_value;
  int state;
  int button_pin;
  int long_hold;

  int *RGB_pins;
  int *RGB_value;
public:
  Wing();
  Wing(int,int,int);

  //Servos
  void set_servos();
  void write_servos();
  void update_motor_values();

  //Potentiometers
  void set_pot_pin(int,int,int);
  void read_pot_value();
  void map_pot_values();
  int* get_pot_pins();
  int* get_pot_value();

  //Light
  void set_RGB_pin(int,int,int);
  void RGB_print(int,int,int);

  //Button
  void set_button_pin(int);
  void set_button_value();
  int get_button_value();
  int get_long_hold_time();
  int get_state();
  void set_state(int);
};

#endif 