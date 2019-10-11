#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield motor_shield = Adafruit_MotorShield(); 
Adafruit_DCMotor *right_motor = motor_shield.getMotor(3);
Adafruit_DCMotor *left_motor = motor_shield.getMotor(4);

//initialize
const int sensor_r_pin = 1;
const int sensor_l_pin = 0;
float sensor_r_value = 0;
float sensor_l_value = 0;
bool r_on = true;
bool l_on = true;
int input = 0;
int incomingByte = 0; // for incoming serial data
int value = 0;

void setup() {
  motor_shield.begin();
  Serial.begin(9600);
}

void loop() {
   // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    input = 0;
    while (true) { 
    incomingByte = Serial.read();
    value = incomingByte -48;
    
    if (value==-38){
      break;
    }

    input = 10*input + value;
    Serial.println(input);
    right_motor->setSpeed(input*0.8);
    left_motor->setSpeed(input);
  }
  }
  Serial.println(input);
  sensor_r_value = analogRead(sensor_r_pin);
  sensor_l_value = analogRead(sensor_l_pin);
  Serial.print("r sensor: ");
  Serial.println(sensor_r_value);
  Serial.print("l sensor: ");
  Serial.println(sensor_l_value);
  if (sensor_r_value > 700) {
    r_on = true;
  } else {
    r_on = false;
  }
  if (sensor_l_value < 700) {
    l_on = true;
  } else {
    l_on = false;
  }

  if (l_on and r_on) {
    Serial.println("go straight");
    right_motor->run(BACKWARD);
    left_motor->run(BACKWARD);
  }
  if (l_on and !r_on) {
    Serial.println("go right");
    right_motor->run(BACKWARD);
    left_motor->run(RELEASE);
  }
  if (!l_on) {
    Serial.println("go left");
    right_motor->run(RELEASE);
    left_motor->run(BACKWARD);
  }
}
