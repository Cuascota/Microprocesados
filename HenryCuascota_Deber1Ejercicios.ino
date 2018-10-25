 int leds[6]={3,4,5,6,7,8}; //  defino vector para configurar 
 int i=0; // variable de recorido del vector
 int k=0;
 long randNumber;
void setup() {
  // put your setup code here, to run once:
for(i=0;i<6;i++){
 pinMode(leds[i],OUTPUT);
 }
 i=0; // reseteo la variable de conteo
 
}

void loop() {
  // put your main code here, to run repeatedly:

   //////////////////////////////////////////////////// ****** ejercicio 1 enecender secuencialmente los numeros impares(1,3,5) ******/////////////////////////////////////////////
 /*
  for(i=1;i<=5;i=i+2){
    digitalWrite(leds[i],HIGH);  // encendiendo posicion i del vector
    delay(200);                  //espero
      }
      for(k=1;k<=5;k=k-2){
        digitalWrite(leds[i],LOW);
        delay(200);
        }
    i=0;    // reset de variable de conteo
*/

              //////////////////////////////////////********** ejercio 2 encender secuencialmente los numeros pares (0,2,4)************///////////////////////////////
   /* 
    for(i=0;i<=5;i=i+2){
    digitalWrite(leds[i],HIGH);  // encendiendo posicion i del vector
    delay(200);                  //espero
      }
      for(k=0;k<=5;k=k-2){
        digitalWrite(leds[i],LOW);
        delay(200);
        }
    i=0;    // reset de variable de conteo
*/
    ///////////////////////////ejercicio 3 generar un numero aleatorio de led metodo random ***********//////////////////////////////////
     for(;i<6;i++){
    randNumber = random(leds[i]);
  digitalWrite(randNumber,HIGH);
  delay(200);
  digitalWrite(randNumber,LOW);
  delay(200);
     }
     i=0;
}
