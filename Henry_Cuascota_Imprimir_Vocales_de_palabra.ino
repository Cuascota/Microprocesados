//Variables de control de lectura de datos 
String valor; // valor que toma el string el valor del dato
int ctoA=0; // contador para las letras mayusculas 
int ctoa=0; // contador para las letras minusculas 

void setup() {
Serial.begin(9600); // inicio comunicacion serial
attachInterrupt(0,comprobar,LOW); // interrupcion para comprobar el dato en cx y verificar 
}

void loop() {
  if (Serial.available()>0) // confirma si ay dato en la entrada de la cx
  {
    valor = Serial.read(); // lee el valor del dato de entrada
  if(valor=="65" || valor=="69" || valor=="73" || valor=="79" || valor=="85") // condiciones de entrada deacuerdo al codigo ASCII para las vocales mayusculas
     {
      ctoA++; // si existen vocales mayusculas el contador se aumneta en uno
     }
     if(valor=="97" || valor=="101" || valor=="105" || valor=="111" || valor=="117" )// condiciones de entrada deacuerdo al codigo ASCII para las vocales minusculas 
     {
      ctoa++; // si existen vocales minusculas el contador se aumneta en uno
     }
  }
 }
   
void comprobar()
{ 
     Serial.println(" "); // espero dato de entrada
     Serial.println("Vocal Mayusculas"); // mensaje paar verificar datos en vocales mayusculas 
     Serial.println(ctoA);               // imprimo el contador de las vocales mayusculas
     Serial.println("Vocal Minusculas"); // mensaje paar verificar datos en vocales minusculas
     Serial.println(ctoa);               // imprimo el contador de las vocales minusculas
  }  

