#include <DC_motor_controller.h>

#include <TwoMotors.h>
#include <My_ultrassonic.h>

DC_motor_controller motorR;
DC_motor_controller motorL;

TwoMotors both(&motorL, &motorR);

My_ultrassonic ultraF(48, 49);

#define led_test 13
#define front_led_right 43
#define front_led_left 42
#define back_led_right 0
#define back_led_left 0

// sensores de linha
#define line1 28 // frente esquerda
#define line2 22 // frente direita
#define line3 26 // trás esquerda
#define line4 24 // trás direita

void interrupt() { motorR.isr(); }
void interrupt2() { motorL.isr(); }

int distance[2] = {0, 0};

void setup() {
   pinMode (led_test, OUTPUT);   
   pinMode (front_led_left, OUTPUT);
   pinMode (front_led_right, OUTPUT);
   /*
   pinMode (back_led_right, OUTPUT);
   pinMode (back_led_left, OUTPUT);
   */

   // Define os pinos dos sensores de linha
   pinMode (line1, INPUT);
   pinMode (line2, INPUT);
   pinMode (line3, INPUT);
   pinMode (line4, INPUT);

   // Motor esquerdo
   motorL.hBridge(46, 47, 8);
   motorL.setRR(30);
   motorL.setEncoderPin(3, 5);
   motorL.setPins();
   motorL.setPIDconstants(1.9, 1, 0.2);
   //motorL.setRefreshTime(40);
   motorL.walk(0);

   // Motor direito
   motorR.hBridge(44, 45, 9);
   motorR.setRR(30);
   motorR.setEncoderPin(2, 4);
   motorR.setPins();
   motorR.setPIDconstants(1.9, 1, 0.2);
   motorR.setRefreshTime(40);
   motorR.walk(0);

   /* razão de rotações para girar 90 graus:
    *  nesse caso-> 1 rotações pra frente em uma roda
    *  e 1.2 rotações pra trás na outra roda
    *  faz com que o robô gire 90 graus para um lado ou para o outro
   */
   both.setGyreDegreesRatio(0.58, 90);

   attachInterrupt(digitalPinToInterrupt(2), interrupt, FALLING);
   attachInterrupt(digitalPinToInterrupt(3), interrupt2, FALLING);

   // Configura os pinos dos sensor ultrassônico
   ultraF.setPins();
   resetMotors();

   // motorR.walk(VELOCIDADE_RPM, NºROTAÇÕES); -> com rotações
  // motorL.walk(VELOCIDADE_RPM); -> andando em velocidade constante
  // both.together(VELOCIDADE_RPM, NºROTAÇÕES);

   digitalWrite (front_led_right, HIGH);
   digitalWrite(front_led_left, HIGH);

   both.together(-45, -0.25);
   both.turnDegree(-45,-135);
   stop(); while(true){
    
   }

      
   int c = 30;
   readDistances();
//   while (readDistances > 15){
    while(true){
  
    motorR.walk(1*c);
    motorL.walk(2*c);
   }
  
}

void loop() {
   both.together(200,1);
}

bool hasLine() {
 return digitalRead(line1)==LOW || digitalRead(line2)==LOW;
}

void readDistances() {
  distance[0] = ultraF.getDistance_cm();
}

void resetMotors() {
  motorR.resetForGyrate();
  motorL.resetForGyrate();
}

void stop() {
  motorL.walk(0);
  motorR.walk(0);
}
