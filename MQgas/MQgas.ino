/*
VCC = 5V
GND = GND
A0 = A0
*/



#include <MQ135.h>
int airquality = 0;
void setup()
{
  Serial.begin(9600);

}
void loop()
{

  int sensorValue = analogRead(A0);
  Serial.print("Air Quality = ");
  Serial.print(sensorValue);

  Serial.print("*PPM");
  Serial.println();
  delay(1000);



}


