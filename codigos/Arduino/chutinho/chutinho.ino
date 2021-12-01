
#include <VarSpeedServo.h> 
#define SERVO 9

VarSpeedServo s;
int pos = 160;

void setup() {
  // put your setup code here, to run once:
  s.attach(SERVO);
  Serial.begin(9600);
 
  
   
  
}

void loop() {
   s.write(90);
   delay(1000);
   s.write(0);
   delay(1000);
  
}

void chutinho (){
  s.write(90,255);
  delay(1000);
  
}
