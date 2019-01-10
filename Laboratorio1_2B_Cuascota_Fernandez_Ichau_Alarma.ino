#include <TimerOne.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd (13,12,11,10,9,8);
int PULSADOR_MODO = 2; // pulsador para modificar hora y crear alarma
int PULSADOR_UP = 3;  // pulsador para aumentar las horas y minutos de pendiendo de la funcion del case
int PULSADOR_DOWN = 4; // pulsador para actualizar el horero
int PULSADOR_MIN = 5;  // pulsador para modificar minutero actualizar la hora y la alarma
int BUZZER = 6;        // indicador de uqe la alarma esta encendida
int horas=0;
int minutos=0;
volatile int segundos=0;
volatile boolean actualizar=true;   // funcion para actualizar declarada inicialmente como verdadera
int horas_alarma=0;                 // variable para alamacenar la hora de la alarma
int minutos_alarma=0;               // variable para alamacenar los minutos de alarma
boolean alarmaOn=false;             // variable para ver el estado de la alarma
int contador_alarma=0;               // contador de la alrma cuenta los segundos que debe durar la alarma

char texto[10];                      // array para poder imprimir texto en la lcd
int modo = 0;                        // variable para caso pulsador_modo
int mod =0;                          // variable para caso pulsador_min
int md=0;                            // variable para caso pulsador_down

void setup(){
   lcd.begin(16,2);
  lcd.clear();
   pinMode(PULSADOR_MODO, INPUT);  // declaramos pulsador_modo como entrada de datos
  pinMode(PULSADOR_UP, INPUT);     // declaramos pulsador_up como entrada de datos
  pinMode(PULSADOR_DOWN, INPUT);   // declaramos pulsador_down como entrada de datos
  pinMode(PULSADOR_MIN, INPUT);    // declaramos pulsador_min como entrada de datos
  pinMode(BUZZER, OUTPUT);         // declaramos buzzer como salida para la alarma
 
  Timer1.initialize(1000000);               //inicializamos el timer one
  Timer1.attachInterrupt(contador);         //metodo para timer one
}

void loop(){
  if(digitalRead(PULSADOR_MODO)==HIGH){    // revisamos estado de el pulsador_modo
    modo++;                                // si pulsador esta en alto el contador se aumenta en uno
    fijarCursorModo();                     // llamamos a este metodo para designar cada posisicion a modificar o actualizar
    while(digitalRead(PULSADOR_MODO)==HIGH); // condicion de funcionamiento cuando pulsador_modo este en alto
  }
  switch(modo){                               // casos para poder incrementar hora, alarma y encender la alarma
    //Incrementar las horas del relog
    case 1:
      if(digitalRead(PULSADOR_UP)==HIGH){     // revisamos estado de el pulsador_up 
        incrementarHoras();                   // si pulsador esta en alto las horas aumenta en uno
        while(digitalRead(PULSADOR_UP)==HIGH); // condicion de funcionamiento cuando pulsador_up este en alto
      }
    break;
    //Ingresar la alarma
    case 2:
      if(digitalRead(PULSADOR_UP)==HIGH){       // revisamos estado de el pulsador_up 
        incrementarHorasAlarma();               // si pulsador esta en alto las horas de alarma aumenta en uno
        while(digitalRead(PULSADOR_UP)==HIGH);  // condicion de funcionamiento cuando pulsador_up este en alto
      }
    break;
    case 3:
      if(digitalRead(PULSADOR_UP)==HIGH){       // revisamos estado de el pulsador_up 
        incrementarMinutosAlarma();             // si pulsador esta en alto los minutos de alarma aumenta en uno
        while(digitalRead(PULSADOR_UP)==HIGH);  // condicion de funcionamiento cuando pulsador_up este en alto
      }
    break;
    case 4:

      if(digitalRead(PULSADOR_UP)==HIGH){       // revisamos estado de el pulsador_up 
        alarmaOn=true;                          // encendemos la alarma
        actualizar=true;
        while(digitalRead(PULSADOR_UP)==HIGH);  // condicion de funcionamiento cuando pulsador_up este en alto
      }
      if(digitalRead(PULSADOR_DOWN)==HIGH){   // revisamos estado de el pulsador_down
        alarmaOn=false;                        // apagamos la alarma
        actualizar=true;                       
        while(digitalRead(PULSADOR_DOWN)==HIGH);// condicion de funcionamiento cuando pulsador_down este en alto
      }  
    break;
  }
  
// pulsador para modificar el minutero actualizar el horero y alarma

  if(digitalRead(PULSADOR_MIN)==HIGH){       // revisamos estado de el pulsador_min
    mod++;                                   // si pulsador esta en alto el contador se aumenta en uno
   fijarCursorMod();                         // llamamos a este metodo para designar cada posisicion a modificar o actualizar
    while(digitalRead(PULSADOR_MIN)==HIGH);  // condicion de funcionamiento cuando pulsador_min este en alto
    }

    switch (mod){                                 // casos para poder incrementar minutos, actualizar hora y alarma
      case 1:
      if(digitalRead(PULSADOR_DOWN)==HIGH){       // revisamos estado de el pulsador_down
        incrementarMinutos();                     // si pulsador esta en alto los minutos aumenta en uno
        while(digitalRead(PULSADOR_DOWN)==HIGH);  // condicion de funcionamiento cuando pulsador_down este en alto
      }
    break;

    case 2:
      if(digitalRead(PULSADOR_DOWN)==HIGH){        // revisamos estado de el pulsador_down
        actualizarReloj();                         // metodo para actualizar relog 
        incrementarHoras();                        // metodo para actualizar horas del reloj
        while(digitalRead(PULSADOR_DOWN)==HIGH);  // condicion de funcionamiento cuando pulsador_down este en alto
      }
    break;

    case 3:
      if(digitalRead(PULSADOR_DOWN)==HIGH){       // revisamos estado de el pulsador_down
        incrementarHorasAlarma();                 // metodo para actualizar horas de alarma
        while(digitalRead(PULSADOR_DOWN)==HIGH); // condicion de funcionamiento cuando pulsador_down este en alto
      }
    break;

    case 4:
      if(digitalRead(PULSADOR_DOWN)==HIGH){      // revisamos estado de el pulsador_down
        incrementarMinutosAlarma();              // metodo para actualizar minutos alarma
        while(digitalRead(PULSADOR_DOWN)==HIGH); // condicion de funcionamiento cuando pulsador_down este en alto
      }
    break;
      }

      if(digitalRead(PULSADOR_DOWN)==HIGH){    // revisamos estado de el pulsador_down
       md++;                                   // si pulsador esta en alto el contador se aumenta en uno
       fijarCursorMd();                        // llamamos a este metodo para designar cada posisicion a modificar o actualizar
      while(digitalRead(PULSADOR_DOWN)==HIGH); // condicion de funcionamiento cuando pulsador_down este en alto
        }
        switch (md){
          case 1:
      if(digitalRead(PULSADOR_UP)==HIGH){      // revisamos estado de el pulsador_up
        incrementarHoras();                    // metodo para actualizar horas de reloj 
        while(digitalRead(PULSADOR_UP)==HIGH); // condicion de funcionamiento cuando pulsador_up este en alto
      }
    break;
          }

  if(actualizar == true){                              // cuando ectualizar es verdadera
    actualizarReloj();                                 // llamamos a metodo actualizar reloj
    lcd.clear();                                       // vaciar datos
    lcd.noBlink();                                     // en la lcd quitamos el parpadeo
    //RELOJ
    lcd.setCursor(0,0);                                // en la posicion 0,0 imprimimos
    sprintf(texto, "%02d:%02d:%02d",horas,minutos, segundos);  // imprimimos cadena de caracteres del reloj
    lcd.print(texto);                                          // imprimimos el texto
    //ALARMA
    lcd.setCursor(0,1);
    sprintf(texto, "%02d:%02d",horas_alarma,minutos_alarma);  // imprimimos cadena de caracteres de alarma
    lcd.print(texto);                                         // imprimimos el texto
    if(alarmaOn ==true){                                                      // si alarma es verdadera entonces pasa a la condicion
      if(segundos==0 && horas == horas_alarma && minutos == minutos_alarma){ // condicion para comparar horas del reloj con alarma
        digitalWrite(BUZZER, HIGH);                                          // si es igual el buzzer se enciende
      }
      lcd.print(" ON");                                                      // mensaje para encendido
    }else{
      lcd.print(" OFF");                                                       // mensaje para apagado
       digitalWrite(BUZZER, LOW);                                              // se apaga el buzzer
    }
    if(contador_alarma==60){                                                   // condicion de conteo de segundos
      digitalWrite(BUZZER, LOW);                                               // si es = a 60 entonces buzzer se apaga
      contador_alarma=0;                                                       // reiniciamos la variable
    } 
     actualizar = false;                                                      // asignamos a actulizar un estado de falso
    fijarCursorModo();                                                        // llamamos al metodo de figar cursor
  }
 
}

void contador(){                       // metodo del timer one
    segundos++;                        // segundos se aumenta constantemente
    if(digitalRead(BUZZER)==HIGH){     // condicion para verificar buzzer
      contador_alarma++;               // contador se aumenta
    }
    actualizar=true;                  // asignamos a actulizar un estado de verdadero
}
void actualizarReloj(){               // metodo para actualizar relog
  minutos += segundos / 60;
  segundos = segundos % 60;
  horas += minutos / 60;
  minutos = minutos % 60;
  horas = horas % 24;
}
void incrementarHoras(){         // metodo para actualizar incremnetar hora del relog
  horas ++;
  horas = horas % 24;
  actualizar=true;
}

void incrementarHorasAlarma(){      // metodo para actualizar incremnetar hora de alarma
  horas_alarma++;
  horas_alarma = horas_alarma % 24;
  actualizar=true;
}
 
void incrementarMinutosAlarma(){        // metodo para actualizar incremnetar minutos de alarma
  minutos_alarma ++;
  minutos_alarma = minutos_alarma % 60;
  actualizar=true;
}
  
void incrementarMinutos(){              // metodo para actualizar incremnetar minutos del relog
  minutos ++;
  minutos = minutos % 60;
  actualizar=true;
}
void fijarCursorMod (){    // metodo para fijar las posiciones cuando entre en funcionamiento el pulsador_Min
  switch (mod){
     case 0:
     lcd.noBlink();
    break;

    case 1:
    lcd.setCursor(3, 0);
      lcd.blink();
    break;

    case 2:
     lcd.setCursor(0, 0);
     lcd.blink();
    break;

    case 3:
      lcd.setCursor(0, 1);
      lcd.blink();
    break; 
    case 4:
      lcd.setCursor(3, 1);
      lcd.blink();
    break;
    }
  }
void fijarCursorModo(){   // metodo para fijar las posiciones cuando entre en funcionamiento el pulsador_modo
  switch(modo){
    case 0:
      lcd.noBlink();
    break;
    case 1:
      lcd.setCursor(0, 0);
      lcd.blink();
    break;

    case 2:
      lcd.setCursor(0, 1);
      lcd.blink();
    break; 
    case 3:
      lcd.setCursor(3, 1);
      lcd.blink();
    break;
    case 4:
      lcd.setCursor(6, 1);
      lcd.blink();
    break;
    
}
}
void fijarCursorMd (){      // metodo para fijar las posiciones cuando entre en funcionamiento el pulsador_down
  switch (md){
 case 0:
      lcd.noBlink();
    break;
    case 1:
      lcd.setCursor(0, 0);
      lcd.blink();
    break;

    case 2:
      lcd.setCursor(0, 1);
      lcd.blink();
    break; 
  }
}
