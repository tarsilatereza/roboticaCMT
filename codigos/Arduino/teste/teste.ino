
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


unsigned long tempo; 
double distancia;

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

int cor3 = digitalRead(SensorExt_dir); 

void loop() {
  if (cor3 == 1){
    frente(100);
  }
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

bool checkLinha(byte a, byte b, byte c, byte d, byte e){
 int sensor[5];
 sensor[0] = digitalRead(SensorExt_dir);
 sensor[1] = digitalRead(Sensor_dir);
 sensor[2] = digitalRead(Sensor_meio);
 sensor[3] = digitalRead(Sensor_esq);
 sensor[4] = digitalRead(SensorExt_esq);

 int cont [5] = {a,b,c,d,e};
 bool check = cont == sensor;
 return check;
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

void volta (){
   ultra();
  if (checkLinha(0, 0, 0, 0, 1)) {
    frente(80);
  } else if (checkLinha(0, 0, 0, 0, 0)) {
    tras(80);
    delay(2000);
    esquerda(60);
    delay(2000);
  }
}
