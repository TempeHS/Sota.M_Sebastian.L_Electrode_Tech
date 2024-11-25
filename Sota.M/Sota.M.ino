#include "<Ultrasonic.h>"

//#include "Ultrasonic.h"

Ultrasonic sensorOne;
void setup()
{
  sensorOne.attach(4);
 Serial.begin(9600);
}
void loop()
{
  long RangeInCentimeters;

  RangeInCentimeters = myUltrasonicSensor.MeasureInCentimeters(); // two measurements should keep an interval
  Serial.print(RangeInCentimeters);//0~400cm
  Serial.println(" cm");
  delay(250);
}