#include <iostream>
#include <stdexcept>
#include <thread>
#include <chrono>

class ChargingManager {
public:
    ChargingManager() {
        std::cout << "Charging manager initialized." << std::endl;
    }

    void startCharging() {
        std::cout << "Starting battery charging..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "Battery charging completed." << std::endl;
    }

    void stopCharging() {
        std::cout << "Stopping battery charging..." << std::endl;
    }

    void checkChargingStatus() {
        std::cout << "Checking charging status: OK." << std::endl;
    }
};