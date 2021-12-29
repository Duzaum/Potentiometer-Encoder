#include <Arduino.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>

int sensorPin = A1;
int pin = A0;
int leitor = 0;
int sensorValue = 0;
long sensor = 0;
int valor = 0;
int h = 0;
int m = 0;
int c = 59;
const int b = 2;
int s = 0;
char a = '-';
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() 
    {
    lcd.begin(16, 2);
    pinMode(b, INPUT_PULLUP);
    }

void loop() {
  leitor = analogRead(sensorPin); //Plots the value of the potentiometer 
  valor = analogRead(pin);

  s = digitalRead (b);
    
   byte highByte = EEPROM.read(511);  // Read the memory
   byte lowByte = EEPROM.read(512);
   sensor  = word(highByte, lowByte);

  sensorValue = leitor/1.08 + sensor;
 
  
  if (valor < 50 && valor >=0) 
  {
    sensor = sensor + 2;
    byte hiByte = highByte(sensor);
    byte loByte = lowByte(sensor);
    EEPROM.write(511,hiByte);  // saving two bytes on memory
    EEPROM.write(512,loByte);
    delay(30);
  }
    
  if (valor >= 300 && valor <500) 
  {
    sensor = sensor - 2;
    byte hiByte = highByte(sensor);
    byte loByte = lowByte(sensor);
    EEPROM.write(511,hiByte);  
    EEPROM.write(512,loByte);
    delay(30);
  }

  if (s == HIGH){
    EEPROM.write(511,0);
    EEPROM.write(512,0);
    delay(20);
  }


  
  
  if (sensorValue == 0)
    {
      h = 7;
      m = 59;
      a = '+';
    }
  
  if (sensorValue < 60 && sensorValue > 0)
    {
      h = 7;
      m = c  - sensorValue;
      a = '+';
    }
   if (sensorValue >= 60 && sensorValue < 120)
    {
      h = 6;
      m = c - (sensorValue-60);
      a = '+';
    }
    if (sensorValue >= 120 && sensorValue < 180)
    {
      h = 5;
      m = c - (sensorValue-120);
      a = '+';
    }
    if (sensorValue >= 180 && sensorValue < 240)
    {
      h = 4;
      m = c - (sensorValue-180);
      a = '+';
    }
    if (sensorValue >= 240 && sensorValue < 300)
    {
      h = 3;
      m = c - (sensorValue-240);
      a = '+';
    }
    if (sensorValue >= 300 && sensorValue < 360)
    {
      h = 2;
      m = c - (sensorValue-300);
      a = '+';
    }
      if (sensorValue >= 360 && sensorValue < 420)
    {
      h = 1;
      m = c - (sensorValue-360);
      a = '+';
    }
      if (sensorValue >= 420 && sensorValue < 480)
    {
      h = 0;
      m = c - (sensorValue-420);
      a = '+';
    }
      if (sensorValue >= 480 && sensorValue < 540)
    {
      h = 0;
      m = sensorValue-480;
      a = '-';
    }
      if (sensorValue >= 540 && sensorValue < 600)
    {
      h = 1;
      m = sensorValue-540;
      a = '-';
    }
      if (sensorValue >= 600 && sensorValue < 660)
    {
      h = 2;
      m = sensorValue-600;
      a = '-';
    }
       if (sensorValue >= 660 && sensorValue < 720)
    {
      h = 3;
      m = sensorValue-660;
      a = '-';
    }
      if (sensorValue >= 720 && sensorValue < 780)
    {
      h = 4;
      m = sensorValue-720;
      a = '-';
    }
      if (sensorValue >= 780 && sensorValue < 840)
    {
      h = 5;
      m = sensorValue-780;
      a = '-';
    }
      if (sensorValue >= 840 && sensorValue < 900)
    {
      h = 6;
      m = sensorValue-840;
      a = '-';
    }
      if (sensorValue >= 900 && sensorValue < 960)
    {
      h = 7;
      m = sensorValue-900;
      a = '-';
    }   
    if (sensorValue >= 960 && sensorValue < 1020)
    {
      h = 8;
      m = sensorValue-960;
      a = '-';
    }
    
   
  lcd.setCursor(4, 0);
  lcd.print("Valor AR:");
  lcd.setCursor(4, 1);
  lcd.print(a);
  lcd.setCursor(5, 1);
  lcd.print(h);
  lcd.setCursor(6, 1);
  lcd.print("h");
  lcd.setCursor(7, 1);
  lcd.print(m);
  lcd.setCursor(9, 1);
  lcd.print("min");

  delay(400);

  lcd.clear();
}
