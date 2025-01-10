#include <iostream>

class DroneComm {
public:
    DroneComm(const std::string& portName, int baudRate)
        : portName_(portName), baudRate_(baudRate) {}

    bool connect() {
        sp_get_port_by_name(portName_.c_str(), &port_);
        if (port_ == nullptr) {
            std::cerr << "Error finding port." << std::endl;
            return false;
        }

        if (sp_open(port_, SP_MODE_READ_WRITE) != SP_OK) {
            std::cerr << "Error opening port." << std::endl;
            return false;
        }

        sp_set_baudrate(port_, baudRate_);
        std::cout << "Connected to drone on port " << portName_ << std::endl;
        return true;
    }

    void sendCommand(const std::string& command) {
        sp_nonblocking_write(port_, command.c_str(), command.size());
    }

    void receiveResponse() {
        char buffer[256];
        int bytesRead = sp_nonblocking_read(port_, buffer, sizeof(buffer) - 1);
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';
            std::cout << "Drone Response: " << buffer << std::endl;
        }
    }

    ~DroneComm() {
        if (port_ != nullptr) {
            sp_close(port_);
            sp_free_port(port_);
        }
    }

private:
    std::string portName_;
    int baudRate_;
    sp_port* port_ = nullptr;
};