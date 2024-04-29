#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Error: WSAStartup failed\n";
        return 1;
    }

    // Create a socket
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Error: Failed to create socket\n";
        WSACleanup();
        return 1;
    }

    // Define the server address
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);  // Example port number
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Error: Bind failed\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Start listening for incoming connections
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Error: Listen failed\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Server started and listening on port 8080\n";

    while (true) {
        // Accept incoming connection
        SOCKET clientSocket = accept(serverSocket, NULL, NULL);
        if (clientSocket == INVALID_SOCKET) {
            std::cerr << "Error: Accept failed\n";
            continue;
        }

        std::cout << "Client connected\n";

        // Handle client request
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead == SOCKET_ERROR) {
            std::cerr << "Error: Read failed\n";
        } else {
            std::cout << "Received message from client: " << buffer << std::endl;
        }

        // Send response back to client
        const char* response = "Hello from server";
        int bytesSent = send(clientSocket, response, strlen(response), 0);
        if (bytesSent == SOCKET_ERROR) {
            std::cerr << "Error: Write failed\n";
        }

        // Close client socket
        closesocket(clientSocket);
    }

    // Close server socket
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
