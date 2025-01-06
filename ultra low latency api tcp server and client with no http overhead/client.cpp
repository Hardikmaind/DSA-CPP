#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;

        // Server endpoint
        tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve("127.0.0.1", "8080");

        // Connect to the server
        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        // Send data to the server
        std::string message = "Hello from C++ Client!";
        boost::asio::write(socket, boost::asio::buffer(message));

        // Receive response from the server
        char response[128];
        size_t length = socket.read_some(boost::asio::buffer(response));
        std::cout << "Server Response: " << std::string(response, length) << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
