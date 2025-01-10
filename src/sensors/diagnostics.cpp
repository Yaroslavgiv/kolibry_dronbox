#include <iostream>
#include <stdexcept>

class Diagnostics {
public:
    void performDiagnostics() {
        try {
            std::cout << "Performing sensor diagnostics..." << std::endl;
            checkTemperatureSensor();
            checkMotionSensor();
            std::cout << "Diagnostics complete: All sensors operational." << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Diagnostics error: " << e.what() << std::endl;
        }
    }

private:
    void checkTemperatureSensor() {
        // Simulate temperature sensor check
        if (rand() % 2 == 0) {
            throw std::runtime_error("Temperature sensor failed");
        }
        std::cout << "Temperature sensor operational." << std::endl;
    }

    void checkMotionSensor() {
        // Simulate motion sensor check
        if (rand() % 2 == 0) {
            throw std::runtime_error("Motion sensor failed");
        }
        std::cout << "Motion sensor operational." << std::endl;
    }
};