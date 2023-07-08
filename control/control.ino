#include "wing.h"

Wing servos = Wing(9,10,11);  //Pines Servo

void setup() {
  //Serial start
  Serial.begin(115200);

  //Attach de motores
  servos.set_servos();

  //Pot pins
  servos.set_pot_pin(A0,A1,A2);
}

void loop() {
  servos.update_values();
  servos.write_servos();
  delay(10);
}
