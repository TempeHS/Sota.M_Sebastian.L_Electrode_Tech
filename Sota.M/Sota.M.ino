#include "Ultrasonic.h"
#include <Servo.h>

Servo myservo;
Ultrasonic dingleberry(5);

#define servoPin 7

int distance;
//unsigned static int potpin = A2;

unsigned long previousMillis;
unsigned long gateTime = (100);
void setup() {
  myservo.attach(servoPin);

  Serial.begin(9600);
}

void loop() {
unsigned long currentMillis = millis();
  distance = dingleberry.distanceRead();
  Serial.println(dingleberry.distanceRead());

  if(dingleberry.distanceRead() >=40)
  {
    previousMillis = currentMillis;
  
     
    myservo.write(0);

     
  } else 
  {
    if(currentMillis - previousMillis >=gateTime)
    myservo.write(180);
  }
}
