/*
 *               UNIVERSIDAD TECNICA DEL NORTE 
 *        FACULTAD DE INGENIERIA EN CIENCIAS APLICADAS
 *      INGENIERIA EN ELECTRONICA Y REDES DE COMUNICACIÓN
 *  
 *  NOMBRE: HENRY CUASCOTA
 *  TEMA: RELOG Y ALARMA INGRESADA POR COMUNICACION SERIAL
 * 
 */
#include <TimerOne.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8); 
int Sec = 0;
int Min = 0;
int Hor = 0;

int buzzer=6;
int ha=0;
int ma=10;
char texto[10];

int segundos=0;
int hora_alarma=0;
int minutos_alarma1=0;
char lectura_hora;
char  lectura_minutos;
boolean alarmaOn=false;
int contador_alarma=0;

boolean actualizar=true;
boolean alarma= false;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
  Timer1.initialize(1000000);
Timer1.attachInterrupt(contador);
  pinMode(buzzer, OUTPUT);
}

void loop() {
   if (Serial.available() > 0) {
    while (Serial.available() > 0) {
             
      lectura_hora = Serial.read(); //leer palabras
      hora_alarma+= lectura_hora;
      
     Serial.println(hora_alarma);
    }
    while (Serial.available() > 0) {
      lectura_minutos = Serial.read(); //leer palabras
      minutos_alarma1 += lectura_minutos;
     
      Serial.println(minutos_alarma1);
  }
  }
if(actualizar == true){
    lcd.setCursor(0, 1);
    //ALARMA
    lcd.print(hora_alarma);
    lcd.setCursor(2, 1);
    lcd.print(":");
    lcd.setCursor(3, 1);
    lcd.print(minutos_alarma1);
    lcd.setCursor(5, 1);
    lcd.print(":");
    lcd.setCursor(8, 1);
    lcd.print("  ALARMA");
    lcd.setCursor(0,1);
   
  if(alarma ==true){
      if(Sec==0 && Hor == hora_alarma && Min == minutos_alarma1){
        digitalWrite(buzzer, HIGH);
      }
    }else{
       digitalWrite(buzzer, LOW);
    }
    if(contador_alarma==60){
      digitalWrite(buzzer, LOW);
      contador_alarma=0;
    }
  actualizar = false;
}
}  
  

void contador()
{
  segundos++;
    
    if(digitalRead(buzzer)==HIGH){
    contador_alarma++;
    }
    actualizar=true;
    
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
