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
#include <netinet/in.h>
#include <set>
#include <map>
#include "ErrIrc.hpp"
#include "Client.hpp"

//--------------------------------------------------------------------------//
//                                 - CLASS -                                //
//--------------------------------------------------------------------------//

class Server
{
//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //

        short                   _port;
        std::string             _ip;
        int                     _socket;
        struct sockaddr_in      _socket_addr;
        std::set<Client *>        _clients;
        std::map<std::string, std::set<int>> _channels;


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
        Server(const char *ip, const char *port);
        ~Server();

    // Operators


    // Getters & Setters


    // Member Functions
        void init();
        void run();
        void sendMessage(const int cSocket, const std::string &message);
        void broadcastMessage(const std::string &channel, const std::string &client, const std::string &message);
        void handleClientConnection(int cSocket);

};

#endif