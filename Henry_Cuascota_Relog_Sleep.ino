#include <TimerOne.h>
#include <LowPower.h> //Librería modos sleep
#include <avr/power.h> //Librería deshabilitar perifericos

#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8); 
int Sec = 0;
int Min = 0;
int Hor = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
  Timer1.initialize(1000000);
Timer1.attachInterrupt(contador);
pinMode(3,INPUT);
pinMode(2,INPUT);
}

void loop() {
  if(digitalRead(3)== LOW){
  lcd.setCursor(0,1);
    lcd.print("Nueva Hora ");
   Hor++;
   lcd.setCursor(14,1);
    lcd.print(Hor);
   delay(300);
  }
  if(digitalRead(2)== LOW){
  lcd.setCursor(0,1);
    lcd.print("Nuevo Minuto ");
   Min++; 
   lcd.setCursor(14,1);
    lcd.print(Min);
   delay(300);
  }
}

void contador()
{
    lcd.clear();
  if(Hor<10){

    lcd.setCursor(0, 0);
    lcd.print(0);
    lcd.setCursor(1,0);
    lcd.print(Hor);
  } 
  else{
    lcd.setCursor(0,0);
    lcd.print(Hor);
  }

  lcd.setCursor(2, 0);
  lcd.print(":");

  if(Min< 10){
    lcd.setCursor(3,0);
    lcd.print(0);
    lcd.setCursor(4,0);
    lcd.print(Min);
  }
  else{
    lcd.setCursor(3, 0);
    lcd.print(Min);
  }

  lcd.setCursor(5, 0);
  lcd.print(":");

  if(Sec< 10){
    lcd.setCursor(6,0);
    lcd.print(0);
    lcd.setCursor(7,0);
    lcd.print(Sec);
  }
  else{
    lcd.setCursor(6,0);
    lcd.print(Sec);
  }
 
  Sec++;
    if(Sec == 60){
      Min++;
      Sec = 0;
    }
    if (Min == 60){
      Hor++;
      Min = 0;
    }
    if(Hor==24)
    {
      Hor=0;
      Min=0;
      Sec=0;
      
      }
 
  }
