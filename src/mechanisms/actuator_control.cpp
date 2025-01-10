#include <iostream>
#include <wiringPi.h>

class ActuatorControl {
public:
    ActuatorControl(int pin) : pin_(pin) {
        wiringPiSetup();
        pinMode(pin_, OUTPUT);
    }

    void activate() {
        digitalWrite(pin_, HIGH);
        std::cout << "Actuator activated on pin " << pin_ << std::endl;
    }

    void deactivate() {
        digitalWrite(pin_, LOW);
        std::cout << "Actuator deactivated on pin " << pin_ << std::endl;
    }

private:
    int pin_;
};
