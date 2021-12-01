/*

    Autor: Hugo Max M. Teixeira
    Janeiro de 2021

    Esta biblioteca tem o objetivo de simplificar a medição de distância feita pelo sensor de distância ultrassônico HC SR04

    My_ultrassonic.cpp

*/

#include <My_ultrassonic.h>

My_ultrassonic::My_ultrassonic(byte t, byte e){
    Trigger = t;
    Echo = e;
}

void My_ultrassonic::setPins(){
    pinMode(Trigger, OUTPUT);
    pinMode(Echo, INPUT);
    digitalWrite(Trigger, LOW);
}

float My_ultrassonic::getDistance_cm(){
    float vel = 0.034; // Velocidade do som em cm/us (centímetros por microssegundo);
    float Distance = 0;
    unsigned long Time;

    for (int i=0; i<3; i++){
        digitalWrite(Trigger, HIGH);
        delayMicroseconds(11);
        digitalWrite(Trigger, LOW);

        Time  = pulseIn(Echo, HIGH);

        Distance += Time * vel / 2.0;
    }

    Distance = Distance / 3.0;

    return Distance;
}

float My_ultrassonic::getDistance_m(){
    float vel = 0.000340; // Velocidade do som em m/us (metros por microssegundo);
    float Distance = 0;
    unsigned long Time;

    for (int i=0; i<3; i++){
        digitalWrite(Trigger, HIGH);
        delayMicroseconds(11);
        digitalWrite(Trigger, LOW);

        Time  = pulseIn(Echo, HIGH);

        Distance += Time * vel / 2.0;
    }

    Distance = Distance / 3.0;

    return Distance;
}
