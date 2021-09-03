//int n1 verde
//int n2 cinza
//n3 verde
//n4 cinza
//PWM1 vermelho
//PWM2 roxo 

#define n1 7
#define n2 6// grupo 1
#define n3 5
#define n4  4// grupo 1
#define PWM1 8
#define PWM2 3
#define echoPin 36 // receber
#define trigPin 37// enviar
#define SensorExt_dir 34
#define Sensor_dir 32
#define Sensor_meio 30
#define Sensor_esq 28
#define SensorExt_esq 26

void setup() {
  // put your setup code here, to run once:
  pinMode(n1, OUTPUT);
  pinMode(n2, OUTPUT);
  pinMode(n3, OUTPUT);
  pinMode(n4, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(SensorExt_dir, INPUT);
  pinMode(Sensor_dir, INPUT);
  pinMode(Sensor_meio, INPUT);
  pinMode(Sensor_esq, INPUT);
  pinMode(SensorExt_esq, INPUT);
  

}

int cor1 = digitalRead(SensorExt_dir);
int cor2 = digitalRead(Sensor_dir);
int cor3 = digitalRead(Sensor_meio);
int cor4 = digitalRead(Sensor_esq);
int cor5 = digitalRead(SensorExt_esq);

void loop() {
  // put your main code here, to run repeatedly:
  if (cor3 == 0) {
    frente (160);
  } 
  if((cor1 == 1) && (cor5 == 0)){
    tras(100);
    delay(300);
  }
  if((cor1 == 0) && (cor5 == 1)){
    tras(100);
    delay(300);
  }

}

void frente(byte vel) {
  digitalWrite(n1, HIGH);
  digitalWrite(n2, LOW);
  digitalWrite(n3, LOW);
  digitalWrite(n4, HIGH);
  analogWrite(PWM1, vel);
  analogWrite(PWM2, vel);
}

void esquerda(byte vel) {
  digitalWrite(n1, HIGH);
  digitalWrite(n2, LOW);
  digitalWrite(n3, LOW);
  digitalWrite(n4, HIGH);
  analogWrite(PWM1, vel);
  analogWrite(PWM2, vel);
}

void tras(byte vel) {
  digitalWrite(n1, HIGH);
  digitalWrite(n2, LOW);
  digitalWrite(n3, HIGH);
  digitalWrite(n4, LOW);
  analogWrite(PWM1, vel);
  analogWrite(PWM2, vel);
}

