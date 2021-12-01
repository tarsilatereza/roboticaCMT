#include <D_ultrassonic.h>



D_ultrassonic::D_ultrassonic(int pinTrigger,int pinEcho){
    this -> trigger = pinTrigger;
    this -> echo = pinEcho;
    pinMode(echo,INPUT);
    pinMode(trigger,OUTPUT);
   
}

float D_ultrassonic::ReturnDistanceInCm(){
      digitalWrite(trigger,HIGH);
      delayMicroseconds(10);
      digitalWrite(trigger,LOW);
      time = pulseIn(echo,HIGH);
      distance = time * kp;
      return distance;
}

float D_ultrassonic::ReturnDistanceInMeter(){
      digitalWrite(trigger,HIGH);
      delayMicroseconds(10);
      digitalWrite(trigger,LOW);
      time = pulseIn(echo,HIGH);
      distance = (time * kp) / 100;
      return distance;
}
