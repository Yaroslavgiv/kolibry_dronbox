class Telemetry {
public:
    void collectData() {
        std::cout << "Collecting telemetry data..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Telemetry data collected: [Temperature: 25C, Load: 40%]" << std::endl;
    }

    void sendData() {
        std::cout << "Sending telemetry data to server..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Telemetry data sent successfully." << std::endl;
    }
};