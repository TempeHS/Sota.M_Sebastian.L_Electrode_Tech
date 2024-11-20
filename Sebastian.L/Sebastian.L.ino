#include <Servo.h>

Servo myServo1; // create servo object to control a servo
Servo myServo2;
static unsigned int degreeOfMovement = 180;    // variable to read the value from the analog pin
static unsigned int lineFollower = 5;

void setup() {
  myServo1.attach(3);  // attaches the servo on pin 9 to the servo object
   myServo2.attach(4);
   {
  Serial.begin(9600);
  pinMode(lineFollower, INPUT);
}
   
}

void loop() {
  {
  {myServo1.write(degreeOfMovement);
delay(500);                                    // waits for the servo to get there
  myServo1.write(0);
delay(500); 
  }
{
    myServo2.write(degreeOfMovement);
    delay(500);                  // sets the servo position according to the set value
   myServo2.write(0);                               // returns the servo to 0
  delay(500);
  } 
  {
  Serial.print("lineFollower:");
  Serial.println(digitalRead(lineFollower));
}                                   
}
}




