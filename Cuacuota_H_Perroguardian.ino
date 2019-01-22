#include <TimerOne.h>

#include <EEPROM.h>

#include <avr/wdt.h>

/*
 * Teamporizador para resetear el sistema
 * Tiene un propio reloj y cuando cumpla su tiempo el sistema a leer la primera posicion...
 * ...de la memoria 
 * activado el watchdog se vuelve a leer
 * el void setup
 * ********************************************************************
 * Libreria <avr/wdt.h>-> Destinada para wdt
 * wdt_enable(tiempo)->tiempo,16MS->8S
 * Milisegundos:15,30,60,120,500
 * segundos:1,2,4,8
 * tiempo -> WDT0_15MS
 * wdt_disable(); ->Desactivar el perro guardian wdt
 * wdt_reset();   ->Borrar registros del wdt
 * **************************************************************************
 */
 //int i=0;
 int on=0;
 int i=EEPROM.read(0);
 
void setup() {
  Timer1.initialize(1000000);
 Timer1.attachInterrupt(timer);
  Serial.begin(9600);
  Serial.println("INICIO");
  attachInterrupt(0,activar,LOW);
  wdt_enable(WDTO_4S);
}

void loop() {
 i++;
 Serial.println(i);
 delay(200);

}

void activar (){
  on=1-on;
  if(on==1)
  wdt_disable();
  else {
    wdt_reset();
    wdt_enable(WDTO_4S);
  }}
  void timer(){
    EEPROM.write(0,i);}
