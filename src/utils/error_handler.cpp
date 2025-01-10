#include <iostream>
#include <stdexcept>

class ErrorHandler {
public:
    static void handleError(const std::string& error) {
        std::cerr << "Error: " << error << std::endl;
    }

    static void throwError(const std::string& error) {
        throw std::runtime_error(error);
    }
};
