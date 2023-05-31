/*
05 = 5v
10 = GND
15 = A4
20 = A5
*/


#include "Keypad.h"
const int buzzer = 10;
const byte ROWS = 4; // number of rows
const byte COLS = 4; // number of columns
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; // row pinouts of the keypad R1 = D8, R2 = D7, R3 = D6, R4 = D5
byte colPins[COLS] = {5, 4, 3, 2};    // column pinouts of the keypad C1 = D4, C2 = D3, C3 = D2
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
 
void setup()
{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}
 
void loop()
{
  char key = keypad.getKey(); 
  if (key)
    if(key=='1'){
      digitalWrite(buzzer,HIGH);
    }
    else{
      digitalWrite(buzzer,LOW);
    }
}