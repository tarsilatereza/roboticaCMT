#ifndef D_ULTRASSONIC_H
#define D_ULTRASSONIC_H

#include <Arduino.h>

class D_ultrassonic{
public:
    D_ultrassonic(int pinTrigger,int pinEcho);
    float ReturnDistanceInCm();
    float ReturnDistanceInMeter();
    

private:
    float distance, kp = 0.017;
    int time;
    int trigger, echo;
};

#endif // D_ULTRASSONIC_h
