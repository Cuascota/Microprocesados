/*
 *      UNIVERSIDAD TECNICA DEL NORTE 
 *          CIERCOM-FICA
 *          
 * NOMBRE: HENRY CUASCOTA
 * TEMA:   configurar el sleep cada 25s
 * 
 */

#include <LowPower.h>

int levantar = 2;

int cnt = 0;
int num = cnt ;

void setup(){  
      Serial.begin(9600);
      pinMode( levantar, INPUT);
   }
void loop(){   
  
    attachInterrupt( 0, configurar, FALLING);
    LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF); 
    detachInterrupt(0); 
       
    if (num != cnt){
      Serial.println(cnt);
       num = cnt ;
       Serial.flush();
          }
   }

void configurar() {    
  cnt++ ;
   }
