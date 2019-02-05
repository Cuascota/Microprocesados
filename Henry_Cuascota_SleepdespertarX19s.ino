/*
 *      UNIVERSIDAD TECNICA DEL NORTE 
 *          CIERCOM-FICA
 *          
 * NOMBRE: HENRY CUASCOTA
 * TEMA:   SISTEMA QUE SE DESPIERTA CADA 19S LEE EL CONVERSOR Y SE VUELVE A DORMIR
 * 
 */
#include <LowPower.h>
#include <MsTimer2.h>
int on=0;
float conversor;
float dato;
void setup()
{
 Serial.begin(9600);
 MsTimer2::set(1000,contador); // timer 2 
 MsTimer2::start();            // inicializamos timer 2
 conversor=analogRead(0); // resive dato del CAD
  dato=(5*conversor)/1023;
  Serial.println(dato);// imprime por cx serial
  delay(500);
 Serial.println("Reset"); 
 
}

void loop() {
  }

void contador (){
if (on<12){
  on++;
  Serial.println(on);
  } if (on==11){
     LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);  // dormir 
  delay(300);// tiempo de espera
   conversor=analogRead(0); // resive dato del CAD
  dato=(5*conversor)/1023;
  Serial.println(dato);// imprime por cx serial
  delay(500);
  }
  }
