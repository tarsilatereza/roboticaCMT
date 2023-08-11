#define pinLed 3
#define button 0


void setup() { 
  Serial.begin (9600); // inicia a comunicação serial
  pinMode (button, INPUT); // define o pino 
  pinMode (pinLed, OUTPUT);
} 

void loop() {

  int leituraLed = digitalRead(pinLed);
  
  int botaoValue = digitalRead(button); // define variável 

  Serial.println (botaoValue, DEC); // envia valor para o serial monitor

  Serial.print ("LED");

  Serial.println (leituraLed);

  if (botaoValue == 1 && button == 0) {

  digitalWrite(pinLed, HIGH);

  button = 1;

  } 

  if (botaoValue == 1 && button == 1) {

  digitalWrite(pinLed, LOW);

  button = 0;
}
  
 // for (sensorValue; sensorValue == 0; sensorValue--){
 // digitalWrite(pinLed, LOW);
 // delay(500);
 // Serial.println ("desligando");
 // }
}
