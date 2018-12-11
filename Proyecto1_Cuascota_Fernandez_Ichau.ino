/*
 *              UNIVERSIDAD TECNICA DEL NORTE 
 *           FICA-CIERCOM-SISTEMAS MICROPROCESADOS
 *  INTREGRANTES:  CUASCOTA HENRY
 *                 FERNANDEZ SERGIO
 *                 ICHAU ALEXANDER
 *  TEMA: Proyecto Primer Bimestre
 *  FECHA: 11/12/2018
 */
#include <Keypad.h>
int dec=13;//display decenas
int uni=12;//display unidades
int X=A2;//Salida display
int Y=A3;//Salida Display
int W=A4;//Salida Display
int Z=A5;//Salida Display
int decenas; // almacenamiento de las decenas
int unidades; // almacenamiento de las unidades

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char pwd [5]={'1','2','3','4','5'};// contraseña usuario 1
char pwr [5]={'5','6','7','8','9'}; // contraseña usuario 2
char pwrs [5]={'1','2','3','4','6'};// contraseña usuario 3
char pwrd [5]={'1','2','3','4','7'}; // contraseña usuario 4
char mst [5]={'4','5','6','7','8'}; // contraseña master 
char nueva[6]={}; // matriz para almacenamiento de una contraseña modificada

int i=0;  // variable para usuario 1
int n=0; // variable para master
int j=0; // variable para Usuario 2
int k=0; // variable para usuario 3
int l=0; // variable para usuario 4
int z=0; // variable para modificar 

char usuario1 [5]; // Cadena donde se guardaran los caracteres de las teclas presionadas
char usuario2 [5]; // Cadena donde se guardaran los caracteres de las teclas presionadas
char usuario3 [5]; // Cadena donde se guardaran los caracteres de las teclas presionadas
char usuario4 [5]; // Cadena donde se guardaran los caracteres de las teclas presionadas
char clavemaster[5]; // Cadena donde se guardaran los caracteres de las teclas presionadas
char nuevac[5];  // variable en donde se almacena 

int on=0; // variable de on off
int usu=0; // variable para usuarios



int ldr1=A1; // sernsor ldr2
int vldr1=0; // lectura del valor en ldr1
int en=0; // asignacion del ldr
int s=0; //alamcenamiento ldr1

int a=0; // variable para identificar si deseamos modificar
int em;  // variable identificador de empleados
int mast=0; // igualdad para la master
char Teclado; 
int con=0; // conteo de personas


char hexaKeys[ROWS][COLS] = {
{'1', '2', '3', '/'},
{'4', '5', '6', '*'},
{'7', '8', '9', '-'},
{'#', '0', '=', '+'}
};
byte rowPins[ROWS] = {11, 10, 9, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4}; //connect to the column pinouts of the keypad
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
void setup() {
   Serial.begin(9600);
  attachInterrupt(0, encendido, FALLING);      // interrupción para el modo encendido, apagado y modificar
   attachInterrupt(1, usuarios, FALLING);    // interrupcion para ingresar empleado
   // para el display 
   pinMode(X,OUTPUT);  // configuracion de pin
   pinMode(Y,OUTPUT); // configuracion de pin
   pinMode(W,OUTPUT); // configuracion de pin
   pinMode(Z,OUTPUT); // configuracion de pin
   pinMode(dec,OUTPUT);   // configuracion de pin
   pinMode(uni,OUTPUT);   // configuracion de pin   
}

void loop() {
   if (on==1){//Coge el valor de la interrupcion
    char Teclado= customKeypad.getKey();
    if (usu==1){               //Lee los caracteres de las teclas presionadas
   if (Teclado != NO_KEY) {  //si el teclado no recibe clave
        usuario1[i]=Teclado;  //posicion en la que esta la clave
        i++;
   }
   if (i==5){
    if(usuario1[0]==pwd[0]&&usuario1[1]==pwd[1]  // comparacion para validar contraseña
    &&usuario1[2]==pwd[2]&&usuario1[3]==pwd[3]  // comparacion para validar contraseña
    &&usuario1[4]==pwd[4]){                       // comparacion para validar contraseña
        Serial.println("CONTRASEÑA CORRECTA");//mensaje  de comparacion
        Serial.println("Ingresando");
        i=0;
        }
        else {
        Serial.println("CONTRASEÑA INCORRECTA");//mensaje de comparacion
        i=0;
        }
        }
        }
   }
   if (usu==2){//trabajador 2 clave
    Teclado= customKeypad.getKey();
   if (Teclado != NO_KEY) {
        usuario2[j]=Teclado;
        j++;
   }
   if (j==5){
    if(usuario2[0]==pwr[0]&&usuario2[1]==pwr[1]  // comparacion para validar contraseña
    &&usuario2[2]==pwr[2]&&usuario2[3]==pwr[3]   // comparacion para validar contraseña
    &&usuario2[4]==pwr[4]){// validacion clave   // comparacion para validar contraseña
        Serial.println("CONTRASEÑA CORRECTA");   //mensaje de comprobacion
        j=0;
        }
        else {
        Serial.println("CONTRASEÑA INCORRECTA");//mensaje de comprobacion 
        j=0;
        }
        }
   }
   if (usu==3){
    Teclado= customKeypad.getKey();
   if (Teclado != NO_KEY) {
        usuario3[k]=Teclado;
        k++;
   }
   if (k==5){
    if(usuario3[0]==pwrs[0]&&usuario3[1]==pwrs[1]  // comparacion para validar contraseña
    &&usuario3[2]==pwrs[2]&&usuario3[3]==pwrs[3]   // comparacion para validar contraseña
    &&usuario3[4]==pwrs[4]){                       // comparacion para validar contraseña
        Serial.println("CONTRASEÑA CORRECTA");     //mensaje de comprobacion
        k=0;
        }
        else {
        Serial.println("CONTRASEÑA INCORRECTA");   //mensaje de comprobacion
        k=0;
        }
        }
   }
   if (usu==4){
    Teclado= customKeypad.getKey();
   if (Teclado != NO_KEY) {
        usuario4[l]=Teclado;
        l++;
   }
   if (l==5){
    if(usuario4[0]==pwrd[0]&&usuario4[1]==pwrd[1]  // comparacion para validar contraseña
    &&usuario4[2]==pwrd[2]&&usuario4[3]==pwrd[3]   // comparacion para validar contraseña
    &&usuario4[4]==pwrd[4]){                      // comparacion para validar contraseña
        Serial.println("CONTRASEÑA CORRECTA");    //mensaje de comprobacion
        l=0;   
        }
        else {
        Serial.println("CONTRASEÑA INCORRECTA");  //mensaje de comprobacion
        l=0;
        }
        }
   }
   if (on == 2) {
     char Teclado= customKeypad.getKey();
    if (Teclado != NO_KEY) {
        clavemaster[n]=Teclado;
        n++;
   }
   if (n==5){
    if(clavemaster[0]==mst[0]&&clavemaster[1]==       // comparacion para validar contraseña
    mst[1]&&clavemaster[2]==mst[2]&&clavemaster[3]     // comparacion para validar contraseña
    ==mst[3]&&clavemaster[4]==mst[4]){                // comparacion para validar contraseña
       Serial.println("CONTRASEÑA CORRECTA");         //mensaje de comprobacion
       mast=1;
       usu=0;
       n=0;;
    }
    else {
        Serial.println("CONTRASEÑA INCORRECTA");     //mensaje de comprobacion
        n=0;
        }
   }
   if(Teclado&&mast==1){   // comparacion si master esta en estado 1
      if(a==0){
        switch (Teclado)     { //casos para camcio de contraseña
            case 'A':        // caso A para modificar empleado 1
            em=1;
            a=1;
        
            break;
            case 'B':      // caso A para modificar empleado 2
            em=2;        
            a=1;
            break;
            
            case 'C':     // caso A para modificar empleado 3
            em=3;
            a=1;
            
            break;
            case 'D':    // caso A para modificar empleado 4
            em=4;
            a=1;
           
            break;
        }
      }

    }
    if(Teclado&&mast==1&&a==1){ // condicion de comparacion y master en 1 y a para identificar si queremos modificar
          Serial.println("NUEVA CONTRASENA"); // mensaje de comprobacion para modificar
          Serial.println(Teclado);  // imprimir los datos que se preciona del teclado
            nueva[k]=Teclado;     // asignar nueva a teclado
            k++;                   // el contador aumneta en 1
        if(k==6&&mast==1){
          if(em==1){         // asignacion de nuevos valores para empleado 1
            pwd[0]=nueva[1];   
            pwd[1]=nueva[2];
            pwd[2]=nueva[3];
            pwd[3]=nueva[4];
            pwd[4]=nueva[5];
            }
            if(em==2){       // asignacion de nuevos valores para empleado 2
            pwr[0]=nueva[1];
            pwr[1]=nueva[2];
            pwr[2]=nueva[3];
            pwr[3]=nueva[4];
            pwr[4]=nueva[5];
            }
            if(em==3){      // asignacion de nuevos valores para empleado 3
           pwrs[0]=nueva[1];
            pwrs[1]=nueva[2];
            pwrs[2]=nueva[3];
            pwrs[3]=nueva[4];
            pwrs[4]=nueva[5];
            }
            if(em==4){      // asignacion de nuevos valores para empleado 4
            pwrd[0]=nueva[1];
            pwrd[1]=nueva[2];
            pwrd[2]=nueva[3];
            pwrd[3]=nueva[4];
            pwrd[4]=nueva[5];
            }
        mast=0; // inicializamos todas las variables en cero
        k=0;
        z=0;
        a=0;
          
         Serial.println("   entrando al sistema  ");   // mensaje para ingresar la nueva contraseña 
      }
      }
   }
       
       if (on==1||on==2){ // comparacion para que el ingreso este siempre prendido
       vldr1=(analogRead(ldr1)*5)/1023; // leemos el valor analogo y convertimos a un voltaje mas bajo
      s=vldr1; //condicion anidada para el aumento del contador
      if (s<3){ // cuando es menor a 3
     en=1;  // asignamos un valor 
      }

      if (en==1){ //
        con++;
        delay(400);
        en=0;
        }
    if(con<99){  // condicion del conteo
       decenas=con/10;  // valor de decenas
       unidades= con-(decenas*10); // valor unidades
       }
      
 digitalWrite(uni,HIGH); // activacion de pin de unidades
 digitalWrite(dec,LOW);  // desactivacion de pin de decenas
 contador(unidades);    // llamo metodo de visualizacion
 delay(100);  // espero
 
 digitalWrite(uni,LOW);   // desactivacion de pin de unidades
 digitalWrite(dec,HIGH);  // activacion de pin de decenas
 contador(decenas);  // llamo metodo de visualizacion
 delay(100); // espero
   }
}

 //Metodo para el encendido, modificar y apagado del sistema
void encendido() {
  switch (on) {//variable para el switch
    case 0:
      Serial.println("SISTEMA ON");//sistema encendido
      on++;
      usu=0;
      i=0;
      n=0;
      break;

      case 1:
      Serial.println("Cambio Contraseña: ");//mensaje
      Serial.println("Ingrese Contraseña master: ");
      on++;
      usu=0;
      i=0;
      n=0;
      break;
      
      case 2:
      if ( nuevac[z]==usuario1[i]){//ingreso nueva clave
      Serial.println("contraseña modificada:");
      on++;
      usu=0;
      i=0;
      z=0;
      }
      else {
         Serial.println("contraseña no modificada:");//mensaje de aviso
        }
      break;

      case 3:
      Serial.println("Sistema OFF");
      on=0;
      usu=0;
      break;

      if (on<4)
      on++;
      else 
      on=0;
  }
}


void usuarios() { //Metodo para la contraseña de los 3 usuarios en el sistema
  if (on == 1 || on == 2  ) {
    switch (usu) {
      case 0:
        Serial.println("Usuario 1");//mensaje para el usuario
        Serial.println("ingrese contraseña: ");//msm de ingreso de clave
        usu++;
        break;

      case 1:
        Serial.println("Usuario 2");// mensaje para el usuario
        Serial.println("ingrese contraseña: ");//msm ingreso de clave
        usu++;
        break;

      case 2:
        Serial.println("Usuario 3");//mensaje para el usuario
        Serial.println("ingrese contraseña: ");//msm ingreso clave
        usu++;
        break;

         case 3:
        Serial.println("Usuario 4");//mensaje para el usuario
        Serial.println("ingrese contraseña: ");//msm ingreso clave
        usu++;
        break;
        
       case 4:
       Serial.println("Todos los empleados entraron");//mensaje si de ingreso
       usu=0;
       break;

        if (usu < 5)
          usu++;
        else
          usu = 0;
    }
  }
}



void contador (int c){
switch(c){
  //0
  case 0:
digitalWrite(X,LOW);//salida a display
digitalWrite(Y,LOW);//salida a display
digitalWrite(W,LOW);//salida a display
digitalWrite(Z,LOW);//salida a display
break;
//1
 case 1:
digitalWrite(X,HIGH);//salida a display
digitalWrite(Y,LOW);//salida a display
digitalWrite(W,LOW);//salida a display
digitalWrite(Z,LOW);//salida a display
break;
//2
case 2:
digitalWrite(X,LOW);//salida a display
digitalWrite(Y,HIGH);//salida a display
digitalWrite(W,LOW);//salida a display
digitalWrite(Z,LOW);//salida a display
break;
//3
case 3:
digitalWrite(X,HIGH);//salida a display
digitalWrite(Y,HIGH);//salida a display
digitalWrite(W,LOW);//salida a display
digitalWrite(Z,LOW);//salida a display
break;
//4
case 4:
digitalWrite(X,LOW);//salida a display
digitalWrite(Y,LOW);//salida a display
digitalWrite(W,HIGH);//salida a display
digitalWrite(Z,LOW);//salida a display
break;
//5
case 5:
digitalWrite(X,HIGH);//salida a display
digitalWrite(Y,LOW);//salida a display
digitalWrite(W,HIGH);//salida a display
digitalWrite(Z,LOW);//salida a display
break;
//6
case 6:
digitalWrite(X,LOW);//salida a display
digitalWrite(Y,HIGH);//salida a display
digitalWrite(W,HIGH);//salida a display
digitalWrite(Z,LOW);//salida a display
break;
//7
case 7:
digitalWrite(X,HIGH);//salida a display
digitalWrite(Y,HIGH);//salida a display
digitalWrite(W,HIGH);//salida a display
digitalWrite(Z,LOW);//salida a display
break;
//8
case 8:
digitalWrite(X,LOW);//salida a display
digitalWrite(Y,LOW);//salida a display
digitalWrite(W,LOW);//salida a display
digitalWrite(Z,HIGH);//salida a display
break;
//9
case 9:
digitalWrite(X,HIGH);//salida a display
digitalWrite(Y,LOW);//salida a display
digitalWrite(W,LOW);//salida a display
digitalWrite(Z,HIGH);//salida a display
break;
}
}
