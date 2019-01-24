/*
 *                  UNIVERSIDAD TECNICA DEL NORTE 
 *                          FICA-CIERCOM
 * Nombre: Henry Cuascota
 * Tema: Deber perro guardian activado por la entrada analogica
 * 
 */
#include <MsTimer2.h>   
#include<avr/wdt.h> // libreria para el perro guardian
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8); 

float dato;   // variable para mostrar dato analogico
int cont;     // contador para reinicio en 10s
int i=0;      // contador para reinicio en 20s
int j=0;      // contador para reinicio en 30s
int k=0;      // contador para reinicio en 40s

void setup() {
 Serial.begin(9600);           // iniciamos comunicacion serial
 lcd.begin(16,2);              // iniciamos lcd
 MsTimer2::set(1000,contador); // timer 2 
 MsTimer2::start();            // inicializamos timer 2
 Serial.println("Reset");      // mensaje de reset
}

void loop() {
    dato=(analogRead(0)*5.0)/1023.0;   // dato de entrada analogica 
    delay(500);                        // timepo de espera
    lcd.clear();                       // boramos todo en la lcd
    lcd.setCursor(0,0);                // posiscion para imprimir mensaje
    lcd.print("El dato es: ");         // mensaje en lcd
    lcd.setCursor(11,0);               // mensaje para imprimir dato 
    lcd.print(dato);                   // imprimimos dato

}
void contador(){
  if (dato>0&&dato<1){                                    // condicion de dato si cumple se reinia en 10s
    Serial.println("El sistema se reiniara en 10s: ");   // mensaje de comprobacion de estado
    cont++;                                              // contador se aumenta en uno 
    Serial.println(cont);                                // imprimimos contador
    if(cont==6)                                          // condicion si contador es igual al valor entonces activo wacht dog a 4s
    {
      wdt_enable(WDTO_4S);                                // inicia wacht dog en 4s
      }
    }
    if(dato>1&&dato<2){                                    // condicion de dato si cumple se reinia en 20s
     Serial.println("El sistema se reiniara en 20s: ");   // mensaje de comprobacion de estado
    i++;                                                  // contador se aumenta en uno
    Serial.println(i);                                    // imprimimos contador
    if(i==16)                                             // condicion si contador es igual al valor entonces activo wacht dog a 4s
    {
      wdt_enable(WDTO_4S);                                 // inicia wacht dog en 4s 
      }
    }
    if (dato>2&&dato<3){                                   // condicion de dato si cumple se reinia en 30s
      Serial.println("El sistema se reiniara en 30s: ");   // mensaje de comprobacion de estado
      j++;                                                 // contador se aumenta en uno
      Serial.println(j);                                   // imprimimos contador
      if(j==26){                                           // condicion si contador es igual al valor entonces activo wacht dog a 4s
        wdt_enable(WDTO_4S);                                // inicia wacht dog en 4s
        }
      }
        if (dato>3&&dato<4){                               // condicion de dato si cumple se reinia en 40s
      Serial.println("El sistema se reiniara en 40s: ");   // mensaje de comprobacion de estado
      k++;                                                 // contador se aumenta en uno
      Serial.println(k);                                   // imprimimos contador
      if(k==36){                                          // condicion si contador es igual al valor entonces activo wacht dog a 4s
        wdt_enable(WDTO_4S);                              // inicia wacht dog en 4s
        }
      }
  }
