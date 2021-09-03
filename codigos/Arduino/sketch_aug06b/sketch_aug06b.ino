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
int ver = 0;

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
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  
}
void tras(byte vel) {
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

void frente(byte vel) {
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
      tras(190);
    }
    
    if((cor1 == 1) && (cor5 == 1) ){
     // Serial.println("Virar");
      frente(120); 
      delay(1000);
      direita(115);
      delay(350);
    }


    if((cor1 == 1) && (cor5 == 0)) {
      frente(90);
      delay(800);
      esquerda(90);
      delay(300);
    }

    if((cor1 == 0) && (cor5 == 1)) {
      frente(90);
      delay(800);
      direita(90);
      delay(300);
    }
}

void loop() {
  // 0 preto 
  // 1 
  // checkobj();
   //checkarena();
   ultra();
   checkobj();
   //checkarena();

}


void checkobj() {
  if(distancia <= 22) {
    while(true){
      frente(250);
      digitalWrite(2,HIGH);
      
    }
  }
  if(distancia > 22){
    digitalWrite(2,LOW);
      tras(100);
      delay(1000);
      direita(100);
      delay(800);
      frente(100);
      delay(1000);
      esquerda(100);
      delay(800);
    
  }
}

void checkarena(){
  for(int i = 0; i <= 4; i ++){
    int cor[i] = {
      cor[0] = digitalRead(SensorExt_dir),
      cor[1] = digitalRead(Sensor_dir),
      cor[2] = digitalRead(Sensor_meio),
      cor[3] = digitalRead(Sensor_esq),
      cor[4] = digitalRead(SensorExt_esq)
    };
    ver = cor[i];
    if((ver == 1) && (i == 4)){
      direita(100);
      delay(800);
      frente(100);
      delay(1000);
    }
    if((ver == 1) && (i == 1)){
      esquerda(100);
      delay(800);
      frente(100);
      delay(1000);
    }
  }
}
