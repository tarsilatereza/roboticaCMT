// 13 de outubro
// AUTORES: PEDRO HENRIQUE (https://github.com/Pedrohenr1qq) e TARSILA (https://github.com/tarsilatereza)

#include <DC_motor_controller.h>
#include <TwoMotors.h>

//sensores
#define led_right
#define led_left
#define sensor_mid
#define ldr_right
#define ldr_left

//motor
#define n1
#define n2
//motor 
#define n3
#define n4

//ultrassonico
#define echo 
#define trig

void setup() {
  // put your setup code here, to run once:
  pinMode(led_right,OUTPUT);
  pinMode(led_left,OUTPUT);
  pinMode(sensor_mid,INPUT);
  pinMode(ldr_right,INPUT);
  pinMode(ldr_left,INPUT);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(n1,OUTPUT);
  pinMode(n2,OUTPUT);
  pinMode(n3,OUTPUT);
  pinMode(n4,OUTPUT);

  digitalWrite(trig,LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  frente();
  mov();
  
}

float distancia;
unsigned long tempo;

void ultra(){
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);

  tempo = pulseIn(echo,HIGH);
  distancia = tempo/58.82;
}


void frente(){
  both.together(100,1);
}

void tras(){
  both.together(-100,-1);
}

void direita(){
  motorR.walk(-100);
  motorL.walk(100);
}

void esquerda(){
  motorR.walk(100);
  motorL.walk(-100);
}

//String cor;

bool vercor(byte sensor, String cor){
  bool c = sensor == cor ? true : false;

  return c;
}

int contverd = 0;
int contverm = 0;

void mov(){
  if(vercor(ldr_left,"verde")){
    cont++;
    if(cont == 1 ){
      direta();
    }
    else{
      esquerda();
    }
  }
  else if(vercor(ldr_right,"verde")){
    direita();
  }
  if(vercor(ldr_right,"vermelho")){
    direita()
  }
  else if(vercor(ldr_left,"vermelho")){
    esquerda();
  }
}
