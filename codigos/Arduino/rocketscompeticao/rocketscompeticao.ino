#define n1 12
#define n2 11// grupo 1
#define n3 9
#define n4  10// grupo 1
#define PWM1 13
#define PWM2 8
#define echoPin 21 // receber
#define trigPin 20// enviar
#define SensorExt_dir 34
#define Sensor_dir 32
#define Sensor_meio 30
#define Sensor_esq 28
#define SensorExt_esq 26


unsigned long tempo; 
double distancia;

//bool ida = true;

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

  Serial.begin(9600);
  
}
void frente(byte vel) {
  digitalWrite(n1, LOW);
  digitalWrite(n2, HIGH);
  digitalWrite(n3, LOW);
  digitalWrite(n4, HIGH);
  analogWrite(PWM1, vel);
  analogWrite(PWM2, vel);
  }

void direita(byte vel) {
  digitalWrite(n1, LOW);
  digitalWrite(n2, HIGH);
  digitalWrite(n3, HIGH);
  digitalWrite(n4, LOW);
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

void parar(byte vel){
  digitalWrite(n1, HIGH);
  digitalWrite(n2, HIGH);
  digitalWrite(n3, HIGH);
  digitalWrite(n4, HIGH);
  analogWrite(PWM1, vel);
  analogWrite(PWM2, vel);
}

void ultra() {
    digitalWrite(trigPin, LOW);
    delay(2);
    digitalWrite(trigPin, HIGH);
    delay(10);
    digitalWrite(trigPin, LOW);
    
    tempo = pulseIn(echoPin, HIGH);
    distancia = tempo/58.82; 

    Serial.println(distancia);
}

void loop() {
  ultra

}
