#include <boost/asio.hpp>
#include <iostream>
#include <thread>

using boost::asio::ip::tcp;

void handle_request(tcp::socket& socket) {
    try {
        char data[128];
        boost::system::error_code error;

        // Read data from client
        size_t length = socket.read_some(boost::asio::buffer(data), error);
        if (error == boost::asio::error::eof) return; // Connection closed by client

        // Echo response
        boost::asio::write(socket, boost::asio::buffer(data, length));
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void start_server(short port) {
    try {
        boost::asio::io_context io_context;

        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));

        std::cout << "Server running on port " << port << std::endl;

        while (true) {
            tcp::socket socket(io_context);
            acceptor.accept(socket);

            // Handle the request in a separate thread (or use an async model)
            std::thread(handle_request, std::ref(socket)).detach();
        }
    } catch (std::exception& e) {
        std::cerr << "Server error: " << e.what() << std::endl;
    }
}

int main() {
    const short port = 8080;
    start_server(port);
    return 0;
}
