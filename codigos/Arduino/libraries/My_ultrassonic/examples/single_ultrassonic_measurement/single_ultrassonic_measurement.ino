/*

    Autor: Hugo Max M. Teixeira
    Janeiro de 2021

    Exemplo de código utilizando a biblioteca My_ultrassonic.h
    Este código fáz a medição da distância lida porum sensor de distância ultrassonico conectado
    aos pinos 2 e 3 do Arduino e mostra esse valor no monitor serial da IDE do Arduino

*/


// Faz a inclusão da biblioteca My_ultrassonic.h, dedicada a medição de distância para
// sensores ultrassonicos HC SR04

#include <My_ultrassonic.h>


// Criação do objeto ultra (nome dado a um sesnsor ultrassônico), conectado aos pinos 2 e 3, (2 - pino Trigger, 3 - pino Echo)
My_ultrassonic ultra(2, 3);


float dist; // Declara uma variável do tipo float chamada dist


void setup() {
  // put your setup code here, to run once:
  
  ultra.setPins(); // Configura os pinos do sensor ultrassônico "ultra"

  Serial.begin(9600); // Inicializa a comunicação serial na velocidade 9600
  
}



void loop() {
  // put your main code here, to run repeatedly:
  dist = ultra.getDistance_cm(); // A variável "dist" recebe o valor lido pelo "ultra" em centímetros, por meio do método getDistance_cm();

  Serial.print("\n\n Distancia: "); // Pula duas linhas e mostra " Distancia: " no monitor serial;
  Serial.print(dist);               // Mostra, logo em seguida, o valor da variável dist;

  delay(500); // Espera 500ms
}
