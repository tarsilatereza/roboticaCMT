/*

    Autor: Hugo Max M. Teixeira
    Janeiro de 2021

    Esta biblioteca tem o objetivo de simplificar a medição de distância feita pelo sensor de distância ultrassônico HC SR04

    My_ultrassonic.h

*/

#ifndef MY_ULTRASSONIC_H
#define MY_ULTRASSONIC_H

#include <Arduino.h>

class My_ultrassonic{
public:
    My_ultrassonic(byte t, byte e);
    void setPins();
    float getDistance_cm();
    float getDistance_m();

private:
    byte Trigger, Echo;
};

#endif // MY_ULTRASSONIC_H
