
int vermelho = 4; 
int amarelo = 5;
int verde = 6;
int pedVermelho = 7;
int pedVerde = 8;

void setup() {
pinMode (vermelho, OUTPUT);
pinMode (amarelo, OUTPUT);
pinMode (verde, OUTPUT);
pinMode (pedVermelho, OUTPUT);
pinMode (pedVerde, OUTPUT);
}

void loop() {
digitalWrite (vermelho, HIGH);
digitalWrite (amarelo, LOW);
digitalWrite (verde, LOW);
digitalWrite (pedVerde, HIGH);
digitalWrite (pedVermelho, LOW);
delay (1000);

digitalWrite (vermelho, LOW);
digitalWrite (amarelo, HIGH);
digitalWrite (verde, LOW);
digitalWrite (pedVerde, LOW);
digitalWrite (pedVermelho, HIGH);
delay (1000);

digitalWrite (vermelho, LOW);
digitalWrite (amarelo, LOW);
digitalWrite (verde, HIGH);
digitalWrite (pedVerde, LOW);
digitalWrite (pedVermelho, HIGH);
delay (1000);


}
