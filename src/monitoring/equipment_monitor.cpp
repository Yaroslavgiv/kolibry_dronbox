#include <iostream>
#include <stdexcept>

class EquipmentMonitor {
public:
    void monitorStatus() {
        std::cout << "Monitoring equipment status..." << std::endl;
        if (checkFans()) {
            std::cout << "Fans operational." << std::endl;
        } else {
            std::cerr << "Warning: Fan malfunction detected!" << std::endl;
        }

        if (checkSensors()) {
            std::cout << "Sensors operational." << std::endl;
        } else {
            std::cerr << "Warning: Sensor malfunction detected!" << std::endl;
        }
    }

private:
    bool checkFans() {
        // Simulate fan check
        return rand() % 2 == 0;
    }

    bool checkSensors() {
        // Simulate sensor check
        return rand() % 2 == 0;
    }
};
