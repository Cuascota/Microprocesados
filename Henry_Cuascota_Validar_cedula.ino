char cedula[11], cedula_validacion[11]; // arrays para la intruducir y comprobar numero de cedula
int i=0; 
void setup() {
  Serial.begin(9600); // inicio cx
  Serial.println("Ingrese cedula"); // mensaje para ingresar # cedula
  for (;i<11;i){ // ciclo para verificar si un numero de cedula es mayor o menor a los 11 digitos
    if (Serial.available()>0){ // compruebo dato de entrada
      cedula[i]=Serial.read(); // leo el valor de la entrada y la almaceno en la variable i
      i++; // se aumneta en uno
    }
  }
  Serial.println(" "); // esperando dato de comprobacion
}

void loop() {
  Serial.println("Valide su cedula"); // mensaje de validacion
  for (;i<11;i){  // ciclo para verificar si un numero de cedula es mayor o menor a los 11 digitos
    if (Serial.available()>0){ // verifico nuevamente dato de entrada
      cedula_validacion[i]=Serial.read(); // leo el dato y compruebo
      i++;
    }
  }
  Serial.println(" ");
  if(cedula[0]==cedula_validacion[0]&&cedula[1]==cedula_validacion[1]&&cedula[2]==cedula_validacion[2]&&cedula[3]==cedula_validacion[3]
  &&cedula[4]==cedula_validacion[4]&&cedula[5]==cedula_validacion[5]&&cedula[6]==cedula_validacion[6]&&cedula[7]==cedula_validacion[7]
  &&cedula[8]==cedula_validacion[8]&&cedula[9]==cedula_validacion[9]&&cedula[10]==cedula_validacion[10]){ // comprobacion de cada array con cada array para determinar si es correcta o incorrecta
    Serial.println("Cedula correcta"); // mensaje de validacion 
    Serial.println(" "); // dato 
  }else{
    Serial.println("Cedula incorrecta"); // mensaje de validacion
    Serial.println(" ");
  }
}
