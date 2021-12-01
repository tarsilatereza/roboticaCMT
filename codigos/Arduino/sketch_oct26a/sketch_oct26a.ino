#include <Servo.h>
Servo servo; //definindo servo1
Servo servo2; //definindo servo2
int n1 = 5; //motor1
int n2 = 6; //motor1
int n3 = 7; //motor2
int n4 = 8; //motor2
int i; //variável
int x; //variável
int pwm = 2; //auto explicativo
int sensor = 3; //sensor de final de curso
bool state = 0; //variável do sensor

void setup() {
  servo.attach(6);
  servo.write(0);
  pinMode(n1, OUTPUT);
  pinMode(n2, OUTPUT);
  pinMode(n3, OUTPUT);
  pinMode(n4, OUTPUT);
  pinMode(pwm, OUTPUT);
  pinMode(sensor, INPUT);
}

//enquanto for alto, para trás. Se for baixo, parar

void loop (){
  state = digitalRead(sensor);
  while (state == true) {
  tras();
  state = digitalRead(sensor);
  }
  parar();
}

void frente() {
  digitalWrite(n1, HIGH);
  digitalWrite(n2, LOW);
  digitalWrite(n3, HIGH);
  digitalWrite(n4, LOW);
  analogWrite(pwm, 150);
}

void tras() {
  digitalWrite(n1, LOW);
  digitalWrite(n2, HIGH);
  digitalWrite(n3, LOW);
  digitalWrite(n4, HIGH);
  analogWrite(pwm, 150);
}
void direita() {
  digitalWrite(n1, HIGH);
  digitalWrite(n2, LOW);
  digitalWrite(n3, LOW);
  digitalWrite(n4, HIGH);
  analogWrite(pwm, 150);
}
void esquerda() {
  digitalWrite(n1, LOW);
  digitalWrite(n2, HIGH);
  digitalWrite(n3, HIGH);
  digitalWrite(n4, LOW);
  analogWrite(pwm, 150);
}

void parar() {
  digitalWrite(n1, HIGH);
  digitalWrite(n2, HIGH);
  digitalWrite(n3, HIGH);
  digitalWrite(n4, HIGH);
  analogWrite(pwm, 0);
}

//servo um
void ssubir1() {
  for (i=90; i<=180; i++) {
  servo.write(i);
  delay(10); 
  }
}

void sdescer1() {
  for (i=90; i>=0; i--) {
  servo.write(i);
  delay(10); 
  }
}

//servo dois
void ssubir2(){
  for (x=90; x<=180; x++) { 
  servo.write(x);
  delay(10);
  }
}

void sdescer2(){
  for (x=90; x>=0; x--) { 
  servo.write(x);
  delay(10);
  }
}
