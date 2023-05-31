/*
DHT11
G=GND
U=5V
D=3 (or whichever pin we set it to)
*/

/*
MQ135
VCC = 5V
GND = GND
A0 = A0
*/


#include <dht11.h>
#define DHT11PIN 4
#include <MQ135.h>
int airquality = 0;

dht11 DHT11;

void  setup()
{
  Serial.begin(9600);
 
}

void loop()
{
  Serial.println();

  int chk = DHT11.read(DHT11PIN);
  int sensorValue = analogRead(A0);
  Serial.print("Pollutants = ");
  Serial.print(sensorValue);

  Serial.print("*PPM");
  Serial.println();
  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperature  (C): ");
  Serial.println((float)DHT11.temperature, 2);

  delay(2000);

}