//AUTOR: DOUGLAS SANTOS E LIAH COLINS
//DATA: DEZEMBRO 2021
// DRC FIRA BRASIL



#include <TwoMotors.h>
#include <My_ultrassonic.h>
#include <DC_motor_controller.h>
#include <Servo.h>

DC_motor_controller mot; //definindo o nome
DC_motor_controller mot2; //definindo o nome
My_ultrassonic ultra(26, 28); //UT1     //pinos de 22 até 32
My_ultrassonic ultra_2(30, 32); //UT2

Servo s;

TwoMotors both(&mot, &mot2);


//=================Variáveis globais===============
float dist; //criando uma variável para a distancia
float dist_2; // segundo ultrassonico
float spd = 80;
int rot = 2.0;


void setup() {
  mot.hBridge(10, 9, 8); //pinos da ponte H
  mot.setEncoderPin(2, 4); //pinos do encoder
  mot.setRR(30); //razão da caixa da redução
  mot.setPPR(11); //11 pulsos que o encoder envia para cada volta dada em torno de seu eixo
  mot.setPIDconstants(2, 0.8, 0.15); //constantes  do PID
  attachInterrupt(digitalPinToInterrupt(2), interrupt_motor, FALLING); //interrupção
  mot.stop();

  mot2.hBridge(11, 12, 13); //pinos da ponte H do motor 2
  mot2.setEncoderPin(3, 5); //pinos do encoder do motor 2
  mot2.setRR(30); //razão da caixa de redução
  mot2.setPPR(11); //11 pulsos que o encoder +envia para cada volta dada em torno de seu eixo
  mot.setPIDconstants(1.9, 0.8, 0.15); //constantes  do PID
  attachInterrupt(digitalPinToInterrupt(3), interrupt_motor2, FALLING); //interrupção
  mot2.stop();

  both.setGyreDegreesRatio(1.0, 90);

  ultra.setPins();
  ultra_2.setPins();
  Serial.begin(9600);
}

void interrupt_motor () {
  mot.isr(); //chama o método isr(), que realiza a contagem do pulso
}

void interrupt_motor2 () {
  mot2.isr(); //chama o método isr(), que realiza a contagem do pulso
}

void loop() {

  dist = ultra.getDistance_cm();
  delay(200);
  dist_2 = ultra_2.getDistance_cm();
  Serial.print("UT1: ");
  Serial.println(dist);
  Serial.print("UT2: ");a
  Serial.println(dist_2);

  //pdf();
  //  direita();
  //  while(true);
}

void frente() {
  both.together (50, 4.2); //para andar os dois juntos
}

void tras() {
  both.together (-50, -4.2); //para ir pra trás coloca negativo
}

void direita() {
  both.turnDegree(20, 90); //o primeiro número é a velocidade e o segundo é a quantidade de rotações
  both.stop();
}

void esquerda() {
  mot.stop();
  mot2.stop();
  mot2.walk(80, 1.72);
  mot.stop();
  mot2.stop();
}

void pdf() {
  if (dist > 15 && dist_2 < 15) {
    frente();
  }
  else if (dist <  15 && dist_2 < 15) {
    esquerda();
    frente();
  }
}
