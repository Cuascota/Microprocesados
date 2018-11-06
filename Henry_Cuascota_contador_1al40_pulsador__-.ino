/*
 *         UNIVERSIDAD TECNICA DEL NORTE 
 *                    FICA 
 *                  CIERCOM
 *  NOMBRE: Henry Cuascota 
 *  Deber:  con un pulsador se aumente el valor de un contador (1 al 40) y mediante otro pulsador se reste ese valor.
 * 
 */
 // variables
int A=6;
int B=5;
int C=4;
int D=3;
int sw=2;
int i=0;
int dec=8;
int uni=7;
int decenas;
int unidades;
int sw_1=9;
void setup() {
  // put your setup code here, to run once:
   pinMode(A,OUTPUT);
   pinMode(B,OUTPUT);
   pinMode(C,OUTPUT);
   pinMode(D,OUTPUT);
   pinMode(sw,INPUT);
   pinMode(sw_1,INPUT);
   pinMode(dec,OUTPUT);
   pinMode(uni,OUTPUT);
   
}

void loop() {

if(digitalRead(sw)==HIGH){ // leo el valor del pulsador paar aumentar el contador 
    delay(200);
  if (i<=40){// cuando i sea igual o menor que cuarenta entra a la funcion
  i++; // el contador se aumenta en 1
  decenas=i/10; // contador dividido para las decenas 
  unidades = i - (decenas*10); // metodo para obtener las unidades  el contador menos las decenas por 10
  }
  else{ 
  i=0;
  }
  }
   if (digitalRead(sw_1)==HIGH){ // leo el valor del pulsador si esta en alto se decrementa uno
    delay(200);
    if (i<=40){// cuando i sea igual o menor que cuarenta entra a la funcion
      i--; // el contador se decrementa en 1
      decenas=i/10;
      unidades=i-(decenas*10);
      }
    
    }
  digitalWrite(uni,HIGH);
  digitalWrite(dec,LOW);
  secuencia(unidades);
  delay(100);

  digitalWrite(uni,LOW);
  digitalWrite(dec,HIGH);
  secuencia(decenas);
  delay(100);
}
 
void secuencia (int j){
  switch (j){
    case 0:
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  break;
  case 1:
//1
   digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  break;

  case 2:
//2
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  break;
  
//3
case 3:
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  break;
//4
case 4:
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  break;
//5
case 5:
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  break;
//6
case 6:
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  break;
//7
case 7:
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  break;
//8
case 8:
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
  break;
//9
case 9:
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
  break;
  }
}

