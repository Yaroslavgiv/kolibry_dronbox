#include <iostream>
#include <wiringPi.h>

class LightingControl {
public:
    LightingControl(int pin) : pin_(pin) {
        wiringPiSetup();
        pinMode(pin_, OUTPUT);
        std::cout << "Lighting control initialized on pin " << pin_ << std::endl;
    }

    void turnOn() {
        digitalWrite(pin_, HIGH);
        std::cout << "Lighting turned ON on pin " << pin_ << std::endl;
    }

    void turnOff() {
        digitalWrite(pin_, LOW);
        std::cout << "Lighting turned OFF on pin " << pin_ << std::endl;
    }

    void setBrightness(int level) {
        if (level < 0 || level > 100) {
            std::cerr << "Invalid brightness level: " << level << std::endl;
            return;
        }
        pwmWrite(pin_, level * 1023 / 100);
        std::cout << "Brightness set to " << level << "% on pin " << pin_ << std::endl;
    }

private:
    int pin_;
};