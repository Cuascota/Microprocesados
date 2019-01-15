#include <EEPROM.h>

String dato; // variable para almacenar el dato de entrada 
int primero; // variable para cambiar de string a int
String dt;   // variable para almacenar el segundo dato de entrada
int segundo;  // variable para cambiar de string a entero
int modo=0;   // variable para cambiar de estado al ingresar un numero

void setup() {
  Serial.begin(9600); // inicializamos comunicacion serial
  Serial.println("    INGRESE PRIMER NUMERO A COMPROBAR:   "); // Mensaje de inicio
 /* EEPROM.write(2, 0);
  delay(10);
  Serial.println(EEPROM.read(0),HEX);*/
}

void loop() {
  if(Serial.available()>0){  // verificamos dato serial
  dato = Serial.readString(); // dato es igual a lectura de string en la comunicacion serial
  primero=dato.toInt();       // conversion de string a entero   // 
 EEPROM.write(2,primero);                          // guarda el primer dato en la posicion 2
 Serial.print("El numero:  ");                      //mensaje de comprobacion 
 Serial.print(primero);                            // imprime el numero de la primera lectura 
 Serial.println("   se almaceno en la posicion 2");  // mensaje de comprobacion 
 modo++;                                          // se aumenta en uno la variable que almacena estado
 delay(800);
if(modo==1){                                    // condicion de comprobacion de variable que almacena estado
 Serial.println("   INGRESE SIGUIENTE NUMERO A COMPROBAR:   ");
  dt = Serial.readString(); // dato es igual a lectura de string en la comunicacion serial
  segundo=dt.toInt();       // conversion de string a entero   
 EEPROM.write(3,segundo);     // Guardamos el valor de la segunda lectura en la posicion 3
 Serial.print("El numero: ");  // mensaje de comprobacion
 Serial.print(segundo);        // imprimir el numero de la lectura
 Serial.println("   Se almaceno en la posicion 3"); // mensaje de comprobacion
 modo=0;                                          // reinicio variable para cambiar de estado al ingresar un numero
 delay(500);
} 
if (EEPROM.read(2)<EEPROM.read(3)){  // condicion de comprobacion 
  delay(800);
    Serial.println(" Guardado el numero: "); // mensaje de comprobacion 
    Serial.println(EEPROM.read(3));           // imprimimos si se cumple la condicion
    }else {
      Serial.println("Ingrese un numero mayor");  // mensaje si no se cumple la condicion 
      }
  }
} 

