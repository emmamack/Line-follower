#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield motor_shield = Adafruit_MotorShield(); 
Adafruit_DCMotor *right_motor = motor_shield.getMotor(3);
Adafruit_DCMotor *left_motor = motor_shield.getMotor(4);

void setup() {
  motor_shield.begin();
  right_motor->setSpeed(30);
  left_motor->setSpeed(30);

}

void loop() {
  // put your main code here, to run repeatedly:
  right_motor->run(BACKWARD);
  left_motor->run(BACKWARD);
  delay(1000);
}
