 #ifndef SERVER_HPP
#define SERVER_HPP

//--------------------------------------------------------------------------//
//                                - INCLUDES -                              //
//--------------------------------------------------------------------------//

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <set>
#include <map>
#include "Client.hpp"

//--------------------------------------------------------------------------//
//                                 - CLASS -                                //
//--------------------------------------------------------------------------//

class Server
{
//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //

        struct sockaddr_in      server_addr;
        std::set<int, Client>   clients;
        std::map<std::string, std::set<int>> channels;


                           // - FUNCTIONS - //

    // Constructor & Destructors


    // Operators


    // Getters & Setters


    // Member Functions


//--PROTECTED---------------------------------------------------------------//
    protected:
                           // - VARIABLES - //



                           // - FUNCTIONS - //

    // Constructor & Destructors


    // Operators


    // Getters & Setters


    // Member Functions


//--PUBLIC------------------------------------------------------------------//
    public:
                           // - VARIABLES - //



                           // - FUNCTIONS - //

    // Constructor & Destructors
        Server(const std::string &ip, const);
        ~Server();

    // Operators


    // Getters & Setters


    // Member Functions
        void sendMessage(const int cSocket, const std::string &message);
        void broadcastMessage(const std::string &channel, const std::string &client, const std::string &message);
        void handleClientConnection(int cSocket);

};

#endif