 #ifndef CLIENT_HPP
#define CLIENT_HPP

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

//--------------------------------------------------------------------------//
//                                 - CLASS -                                //
//--------------------------------------------------------------------------//

class Client
{
//--PRIVATE-----------------------------------------------------------------//
    private:
                           // - VARIABLES - //
        const int               socket;
        const std::string       name;
        std::set<std::string>   channels;


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
        Client();
        Client(Client &client);
        ~Client();


    // Operators
        Client &operator=(const Client &client);

    // Getters & Setters


    // Member Functions


};

#endif