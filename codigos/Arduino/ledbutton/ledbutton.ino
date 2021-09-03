// Declarar as portas

int button = 6;
int led = 3;

// O professor explicou que o estado era booleano e não uma variável de número inteiro. Faz sentido mas acho que funcionária se fosse com "int" também, não sei direito.

bool estado_led = true; 
bool press_button = true;  

void setup (){

    pinMode(led, OUTPUT);
    pinMode(button, OUTPUT);

}

void loop (){
  
  press_button = digitalRead(button);
  estado_led = digitalRead(led);

// Acho que nem precisaria de uma variável pra guardar o valor do led, daria certo só fazendo as codicionais com if (led == HIGH) ou if (led == LOW), não sei se é uma boa prática mas funciona do mesmo jeito. Como eu tenho certeza que ia me confundir com os HIGH e LOW coloquei o valor do led dentro do booleano estado_led.
    
  Serial.begin(9600);    // Comecei o Serial, pode acompanhar pelo monitor do Arduino IDE ou pelo monitor do tinkercad mesmo.

  if ((press_button == true) && (estado_led == false)) {
    digitalWrite(led, HIGH);
    Serial.println("LIGADO");
    estado_led = true;
    delay(500);

// Se o botão for precionado e o LED estiver desligado entãooo ligue o LED, escreva no monitor "LIGADO" e muda o estado do LED para true. Mas pq (não sei porquês básico) ele muda de false para true, tarsila? É pq a gente vai ter que desligar ele depois, na função else if alí em baixo. Só conseguimos desligar algo que tá ligado :) 

  } else if  ((estado_led == true) && (press_button == true)) {
    digitalWrite(led, LOW);
    Serial.println("DESLIGADO");
    estado_led = false;
    delay(500);

// Se o LED estiver ligado e o botão estiver pressionado entãooooo desliga o LED, escreve no monitor "DESLIGADO" e muda o estado do LED para false. Está dentro da função loop, ou seja, vai ficar repetindo. 
  
  }
    

} // fim do loop 
