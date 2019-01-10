/*
 *               UNIVERSIDAD TECNICA DEL NORTE 
 *        FACULTAD DE INGENIERIA EN CIENCIAS APLICADAS
 *      INGENIERIA EN ELECTRONICA Y REDES DE COMUNICACIÓN
 *  
 *  NOMBRE: HENRY CUASCOTA
 *  TEMA: RELOG Y ALARMA INGRESADA POR COMUNICACION SERIAL
 * 
 */
#include <MsTimer2.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8); 
int Sec = 0;
int Min = 0;
int Hor = 0;
int buzzer=6;
int modo=0;

int hora_alarma;
int minutos_alarma1;
String lectura_hora;
String  lectura_minutos;
int contador_alarma;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
    MsTimer2::set(1000,contador); // metodo para el timer
  MsTimer2::start();//Inicializamos timer
pinMode(3,INPUT);
pinMode(2,INPUT);
pinMode(buzzer, OUTPUT);
}

void loop() {
  if(digitalRead(3)== LOW){
   Hor++;
   delay(300);
  }
  if(digitalRead(2)== LOW){
   Min++; 
   delay(300);
  }

   if (Serial.available() > 0) {   
      lectura_hora = Serial.readString(); //leer palabras
      hora_alarma = lectura_hora.toInt();
      
     Serial.println(hora_alarma);
     modo++;
    delay(400); 
     if (modo==1){
      Serial.println("Ing Minutos:");
      lectura_minutos = Serial.readString(); //leer palabras
      minutos_alarma1 = lectura_minutos.toInt();
      Serial.println(minutos_alarma1);
      modo=0;
  }
  } 
      if(Hor == hora_alarma  && Min == minutos_alarma1){
        contador_alarma++;
        digitalWrite(buzzer, HIGH);
      }  
   else{
     digitalWrite(buzzer, LOW); 
    }

    if(contador_alarma==60){
      digitalWrite(buzzer, LOW);
      contador_alarma=0;
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
      if(hora_alarma<10){
        lcd.setCursor(0, 1);
        lcd.print(0);
        lcd.setCursor(1,1);
        lcd.print(hora_alarma);
      }else{
    lcd.setCursor(0,1);
    lcd.print(hora_alarma);
  }
   lcd.setCursor(2, 1);                                       // posiscion para imprimir valor
    lcd.print(":"); 

     if(minutos_alarma1<10){
        lcd.setCursor(3, 1);
        lcd.print(0);
        lcd.setCursor(4,1);
        lcd.print(minutos_alarma1);
      }else{
    lcd.setCursor(3,1);
    lcd.print(minutos_alarma1);
  }
  
  }
