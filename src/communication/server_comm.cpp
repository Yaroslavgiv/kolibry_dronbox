#include <iostream>

class ServerComm {
public:
    ServerComm(const std::string& server, int port)
        : server_(server), port_(port), context_(boost::asio::ssl::context::sslv23) {}

    void connect() {
        try {
            boost::asio::ip::tcp::resolver resolver(io_context_);
            auto endpoints = resolver.resolve(server_, std::to_string(port_));

            socket_ = std::make_unique<boost::asio::ssl::stream<boost::asio::ip::tcp::socket>>(io_context_, context_);
            boost::asio::connect(socket_->lowest_layer(), endpoints);
            socket_->handshake(boost::asio::ssl::stream_base::client);

            std::cout << "Connected to server." << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void sendCommand(const std::string& command) {
        try {
            boost::asio::write(*socket_, boost::asio::buffer(command));
        } catch (const std::exception& e) {
            std::cerr << "Error sending command: " << e.what() << std::endl;
        }
    }

private:
    std::string server_;
    int port_;
    boost::asio::io_context io_context_;
    boost::asio::ssl::context context_;
    std::unique_ptr<boost::asio::ssl::stream<boost::asio::ip::tcp::socket>> socket_;
};