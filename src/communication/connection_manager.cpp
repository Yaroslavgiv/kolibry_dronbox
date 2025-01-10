#include <iostream>
#include <memory>

#include "server_comm.cpp"

class ConnectionManager {
public:
    ConnectionManager(const std::string& server, int serverPort, const std::string& dronePort, int droneBaudRate)
        : serverComm_(server, serverPort), droneComm_(dronePort, droneBaudRate) {}

    void establishConnections() {
        serverComm_.connect();
        if (droneComm_.connect()) {
            std::cout << "All connections established." << std::endl;
        } else {
            std::cerr << "Failed to connect to drone." << std::endl;
        }
    }

    void sendServerCommand(const std::string& command) {
        serverComm_.sendCommand(command);
    }

    void sendDroneCommand(const std::string& command) {
        droneComm_.sendCommand(command);
    }

private:
    ServerComm serverComm_;
    DroneComm droneComm_;
};
