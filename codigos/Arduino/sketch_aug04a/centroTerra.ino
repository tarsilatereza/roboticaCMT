
#define n1 7
#define n2 6// grupo 1
#define n3 4
#define n4  5// grupo 1
#define PWM1 8
#define PWM2 3
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

void cores() {
    bool cor1 = digitalRead(SensorExt_dir);
    bool cor2 = digitalRead(Sensor_dir);
    bool cor3 = digitalRead(Sensor_meio);
    bool cor4 = digitalRead(Sensor_esq);
    bool cor5 = digitalRead(SensorExt_esq);

    if(cor3 == 0 ){
      //Serial.println("Livre");
      tras(220);
    }
    
    if((cor1 == 1) && (cor5 == 1) ){
     // Serial.println("Virar");
      frente(150); 
      delay(1000);
      direita(115);
      delay(350);
    }

    if((cor1 == 1) && (cor5 == 1)){
      //Serial.println("Virar");
      frente(150); 
      delay(1000);
      esquerda(115);
      delay(350);
    }

    if((cor1 == 1) && (cor5 == 0)) {
      frente(100);
      delay(800);
      esquerda(90);
      delay(350);
    }

    if((cor1 == 0) && (cor5 == 1)) {
      frente(100);
      delay(800);
      direita(90);
      delay(350);
    }
}

void loop() {
  // 0 preto 
  // 1 branco
  cores();
  //ultra();
/*
  if(distancia < 15) {
    frente(100);
    delay(500);
    direita(100);
    delay(1000);
    tras(100);
    delay(500);
    ida = !ida;
  }
  */
}
