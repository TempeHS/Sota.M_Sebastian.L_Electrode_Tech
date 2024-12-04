
/*#include "Ultrasonic.h"
#include <Servo.h>

Servo myservo;
Ultrasonic dingleberry(5);

#define servoPin1 7
int distance;
//unsigned static int potpin = A2;

unsigned long previousMillis;
unsigned long gateTime = (100);
void setup() {
 { myservo.attach(servoPin1);
  Serial.begin(9600);
 }
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
//val = map(analogRead(A0), 0, 1023, 0, 255);
*/
/*
#include <Servo.h>

// Define the servo and ultrasonic sensor pin
Servo myServo;
const int sensorPin = 5; // Single pin for both trigger and echo
const int servoPin = 7;

void setup() {
  // Set up the ultrasonic sensor pin
  pinMode(sensorPin, OUTPUT);
  
  // Attach the servo motor to the specified pin
  myServo.attach(servoPin);
  
  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  long duration, distanceCm;
  
  // Send a pulse to trigger the ultrasonic sensor
  pinMode(sensorPin, OUTPUT);
  digitalWrite(sensorPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sensorPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorPin, LOW);
  
  // Switch the pin to input to read the echo
  pinMode(sensorPin, INPUT);
  duration = pulseIn(sensorPin, HIGH);
  
  // Calculate the distance in cm
  distanceCm = duration * 0.034 / 2;
  
  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");
  
  // Map the distance to the servo angle (0 to 180 degrees)
  int servoAngle = map(distanceCm, 0, 100, 0, 180);
  
  // Constrain the servo angle to valid range
  servoAngle = constrain(servoAngle, 0, 180);
  
  // Move the servo to the corresponding angle
  myServo.write(servoAngle);
  
  // Small delay to avoid overwhelming the servo motor
  delay(15);
}
*/

#include <Servo.h>

// Define the servo and ultrasonic sensor pin
Servo myServo1;
Servo myServo2;
const int sensorPin = 5; // Single pin for both trigger and echo
const int servoPin1 = 7;
const int servoPin2 = 6;

// Variable to store the last servo position
int lastServoAngle = 0;

void setup() {
  // Set up the ultrasonic sensor pin
  pinMode(sensorPin, OUTPUT);
  
  // Attach the servo motor to the specified pin
  myServo1.attach(servoPin1);
  myServo2.attach(servoPin2);
  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  long duration, distanceCm;
  
  // Send a pulse to trigger the ultrasonic sensor
  pinMode(sensorPin, OUTPUT);
  digitalWrite(sensorPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(sensorPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorPin, LOW);
  
  // Switch the pin to input to read the echo
  pinMode(sensorPin, INPUT);
  duration = pulseIn(sensorPin, HIGH);
  
  // Calculate the distance in cm
  distanceCm = duration * 0.034 / 2;
  
  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");
  
  // Map the distance to the servo angle (0 to 180 degrees)
  int servoAngle = map(distanceCm, 0, 100, 0, 180);
  
  // Constrain the servo angle to valid range
  servoAngle = constrain(servoAngle, 0, 180);

  // Check if the servo needs to move to a new position
  if (servoAngle != lastServoAngle) {
    // Move the servo to the corresponding angle
    myServo1.write(servoAngle);
    myServo2.write(servoAngle);
    // Update the last servo position
    lastServoAngle = servoAngle;
  }
  
  // Small delay to avoid overwhelming the servo motor
  delay(15);
}
