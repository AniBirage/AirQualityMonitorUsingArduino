/*
05 = 5v
10 = GND
15 = A4
20 = A5
*/

/*
DHT11
G=GND
U=5V
D=4 (or whichever pin we set it to)
*/

/*
MQ135
VCC = 5V
GND = GND
A0 = A0
*/

/*
OLED
VDD = 5V
GND = GND
SCK = A5
SDA = A4
*/
//buzzer = 11

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <dht11.h>
#define DHT11PIN 4
#include <MQ135.h>
#include "Keypad.h"


#define i2c_Address 0x3c

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16

const int buzzer = 11;
const int trigPin = 10;
const int echoPin = 11;
const int relayPin = 12;
long duration;
float distance;
float percentage;
int airquality = 0;
dht11 DHT11;

void display_air(int sensor){
  display.clearDisplay();
  display.setCursor(0,15);
  display.print("Pollutants = ");
  display.print(sensor);
  display.println(" PPM");
  display.display();
}

void display_temphum(int humid, int temp, int sensor){
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Humidity = ");
  display.print(humid);
  display.println("%");
  display.println();
  display.print("Temperature = ");
  display.print(temp);
  display.println("C");
  display.println();
  display.print("Pollutants = ");
  display.print(sensor);
  display.println(" PPM");
  display.println();
  display.println(" Overall Air Quality");
  display.setCursor(32,55);
  if (sensor < 400){
    display.print("Good");
  }
  else if(sensor>400 && sensor<600){
    display.print("Moderate");
  }
  else if(sensor >600 && sensor < 800){
    display.print("Unhealthy");
  }
  else{
    display.print("Hazardous");
  }
  display.display();
}

void buzzerup(int val){
  if (val>=800){
    display.clearDisplay();
    display.display();
    display.setTextSize(6);
    display.setCursor(5, 5);
    display.println("RUN");
    /*display.println("IS HAZARDOUS");
    display.println();
    display.println("PLEASE GET TO");
    display.println("A SAFE SPACE");*/
    display.display();
    digitalWrite(buzzer,HIGH);
    delay(1500);
  }
  else{
        digitalWrite(buzzer,LOW);
        display.setTextSize(1);
  }
}

void  setup()
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(relayPin,OUTPUT);
  Serial.begin (9600);
  pinMode(buzzer, OUTPUT);
  delay(250);
  display.begin(i2c_Address, 0x3C);
 
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);
  display.display();

 
}

void loop()
{    
  digitalWrite(buzzer,LOW);
  int chk = DHT11.read(DHT11PIN);
  int sensorValue = analogRead(A0);
  buzzerup(sensorValue);
  Serial.print("Pollutants = ");
  Serial.print(sensorValue);
  Serial.print(" PPM");
  Serial.println();
  //display_air(sensorValue);
  
  //delay(4000);

  Serial.print("Humidity: ");
  Serial.print((float)DHT11.humidity, 2);
  Serial.println(" %");

  Serial.print("Temperature: ");
  Serial.print((float)DHT11.temperature, 2);
  Serial.println("°C");
  display_temphum((float)DHT11.humidity, (float)DHT11.temperature, sensorValue);
  delay(1000);

}