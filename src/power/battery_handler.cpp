#include <iostream>
#include <stdexcept>

class BatteryHandler {
public:
    BatteryHandler() {
        std::cout << "Battery handler initialized." << std::endl;
    }

    void monitorBatteryHealth() {
        std::cout << "Monitoring battery health: All batteries are healthy." << std::endl;
    }

    void replaceBattery() {
        std::cout << "Replacing battery..." << std::endl;
        std::cout << "Battery replacement completed." << std::endl;
    }

    void checkBatteryLevel() {
        int level = 80; // Simulated battery level
        std::cout << "Battery level: " << level << "%" << std::endl;
        if (level < 20) {
            std::cerr << "Warning: Battery level low!" << std::endl;
        }
    }
};