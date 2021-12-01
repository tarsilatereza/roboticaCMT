/*

    Autor: tarsila tereza 
    Outubro de 2021
    Feito para controlar o servo motor - BIBLIOTECA: 
*/
#include <Servo.h>
#include <D_ultrassonic.h>

#define SERVO 7

Servo s; //gjgjjttjtyt
int pos;


// Criação do objeto ultra (nome dado a um sesnsor ultrassônico), conectado aos pinos 2 e 3, (2 - pino Trigger, 3 - pino Echo)
D_ultrassonic ultra(2, 3);


float dist; // Declara uma variável do tipo float chamada dist


void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial na velocidade 9600
  s.attach(SERVO);
  s.write(0);
}



void loop() {
  dist = ultra.ReturnDistanceInCm(); // A variável "dist" recebe o valor lido pelo "ultra" em centímetros, por meio do método ReturnDistanceInCm();
  Serial.print(" Distancia: \n"); // Mostra " Distancia: " no monitor serial;
  Serial.print(dist);               // E depois mostra o valor da variável dist;
  delay(500); // Espera 500ms



  
}
