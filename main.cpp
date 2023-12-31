#include <iostream>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "irc.h"

int main(int argc, char  **argv)
{   
    if (argc != 3)
    {
        std::cerr << "Error\nWrong number of arguments, IP then Port needed.\n" << std::endl;
        return (1);
    }
    
    if (check_ip(argv[1]))
    {
        std::cerr << "Error\nWrong IP format.\n";
        return (1);
    }

    const int   port = atoi(argv[2]);
    if (port < 1024 || port > 65535)
    {
        std::cerr << "Error\nWrong Port format.\n";
        return (1);
    }
    
    Server  server(argv[1], argv[2]);

    try
    {
        server.init();
        server.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

//
    //// Lier le socket à l'adresse et au port
    //if (bind(serverSocket, reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress)) == -1) {
    //    std::cerr << "Erreur lors de la liaison du socket : " << strerror(errno) << std::endl;
    //    close(serverSocket);
    //    return EXIT_FAILURE;
    //}
//
    //// Mettre en écoute le socket
    //if (listen(serverSocket, BACKLOG) == -1) {
    //    std::cerr << "Erreur lors de la mise en écoute du socket : " << strerror(errno) << std::endl;
    //    close(serverSocket);
    //    return EXIT_FAILURE;
    //}
//
    //std::cout << "Le serveur est en écoute sur le port " << PORT << "..." << std::endl;
//
    //// Accepter les connexions entrantes
    //sockaddr_in clientAddress;
    //socklen_t clientSize = sizeof(clientAddress);
    //int clientSocket = accept(serverSocket, reinterpret_cast<sockaddr*>(&clientAddress), &clientSize);
//
    //if (clientSocket == -1) {
    //    std::cerr << "Erreur lors de l'acceptation de la connexion : " << strerror(errno) << std::endl;
    //    close(serverSocket);
    //    return EXIT_FAILURE;
    //}
//
    //std::cout << "Nouvelle connexion acceptée." << std::endl;
//
    //// Fermer les sockets
    //close(clientSocket);
    //close(serverSocket);
//
    //return EXIT_SUCCESS;
}