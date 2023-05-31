#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

//Ammonia(NH3), Benzene(C6H6), Smoke, Alcohol and Carbon dioxide(CO2).


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

const int trigPin = 10;
const int echoPin = 11;
const int relayPin = 12;
long duration;
float distance;
float percentage;

void setup()   {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(relayPin,OUTPUT);
  Serial.begin (9600);
  delay(250);
  display.begin(i2c_Address, 0x3C);
 
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);
  display.display();
}


void loop() {;
  display.setCursor(25,15);
  display.println("test");
  display.display();
}