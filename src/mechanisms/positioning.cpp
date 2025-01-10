#include <iostream>
#include <cmath>

class Positioning {
public:
    void calculatePosition(double x, double y, double z) {
        double distance = std::sqrt(x * x + y * y + z * z);
        std::cout << "Drone position calculated: Distance = " << distance << " units" << std::endl;
    }

    void alignForLanding() {
        std::cout << "Drone aligned for landing." << std::endl;
    }
};