// Lib source : https://github.com/AndreaLombardo/L298N/
#include <L298NX2.h>



// Pin definition
const unsigned int EN = 1;
const unsigned int IN1 = 4;
const unsigned int IN2 = 2;
const unsigned int potentPin = 3;


const int middlePotValue = 524; // Analog value when pot is in middle position
const int minSpeed=60; // Minumum value for motor to turn
const int maxSpeed=225; // 90% of 250 for safety
const int threshold = 40; // Dead zone range


// Initialize motor
L298N motor(EN, IN1, IN2);


int potentValue = 0;
void setup()
{
  pinMode(EN, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(potentPin, INPUT);
}


void loop()
{
  int rawPotValue = analogRead(potentPin);
  potentValue = rawPotValue-middlePotValue;
  if(potentValue<0 && potentValue<-threshold){
    int speed = map(abs(potentValue + threshold), 0, middlePotValue - threshold, minSpeed, maxSpeed);
    motor.setSpeed(max(speed, minSpeed));
    motor.backward();
  }else if(potentValue > threshold){
    int speed = map(abs(potentValue - threshold), 0, middlePotValue - threshold, minSpeed, maxSpeed);
    motor.setSpeed(max(speed, minSpeed));
    motor.forward();
  }else{
    motor.stop();
  }
  delay(100);
}