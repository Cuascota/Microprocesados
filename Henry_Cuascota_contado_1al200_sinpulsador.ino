/*
 *         UNIVERSIDAD TECNICA DEL NORTE 
 *                    FICA 
 *                  CIERCOM
 *  NOMBRE: Henry Cuascota 
 *  Deber:  contador del 1 al 200 sin pulsador 
 * 
 */
 // variables 
int A=6;
int B=5;
int C=4;
int D=3;
int i=0;
int dec=8;
int uni=7;
int cen=9;
int centenas;
int decenas;
int unidades;
void setup() {
  // put your setup code here, to run once:
   pinMode(A,OUTPUT);
   pinMode(B,OUTPUT);
   pinMode(C,OUTPUT);
   pinMode(D,OUTPUT);
   pinMode(dec,OUTPUT);
   pinMode(uni,OUTPUT);
   pinMode(cen,OUTPUT);
   
}

void loop() {
for(i=0;i<=201;i++){ // funcion para determinar los numeros del 1 al 200
  centenas = i/100; // el contador lo divido para las centenas 
  decenas=(i%100)/10;// saco el residuo y lo divido para 10 que seria las decenas 
  unidades = (i%100)%10; // el residuio de las centenas y el residuo de las decenas para obtener las unidades 

  digitalWrite(uni,HIGH); // enciendo el display unidades 
  digitalWrite(dec,LOW); // apago decenas 
  digitalWrite(cen,LOW); // apago decenas
  secuencia(unidades); // llamo al metodo y unidades 
  delay(100);          // delay de espera 
  
  digitalWrite(uni,LOW);
  digitalWrite(dec,HIGH); // enciendo decenas 
  digitalWrite(cen,LOW);
  secuencia(decenas);
  delay(100);

  digitalWrite(uni,LOW);
  digitalWrite(dec,LOW);
  digitalWrite(cen,HIGH); // enciendo centenas 
  secuencia(centenas);
  delay(100);
}
i=0;
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

