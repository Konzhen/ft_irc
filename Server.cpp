 #include "Server.hpp"

//--------------------------------------------------------------------------//
//                      - CONSTRUCTORS & DESTRUCTORS -                      //
//--------------------------------------------------------------------------//

Server::Server(const char *ip, const char *port): _ip(ip), _port(atoi(port))
{

}

Server::~Server()
{

}


//--------------------------------------------------------------------------//
//                               - OPERATORS -                              //
//--------------------------------------------------------------------------//



//--------------------------------------------------------------------------//
//                           - GETTERS & SETTERS -                          //
//--------------------------------------------------------------------------//



//--------------------------------------------------------------------------//
//                           - MEMBER FUNCTIONS -                           //
//--------------------------------------------------------------------------//

void    Server::init()
{
    if ((_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        throw std::runtime_error("Error\nServer init - socket creation failed.");
    _socket_addr.sin_family = AF_INET;
    _socket_addr.sin_port = htons(_port);
    _socket_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(_socket, (sockaddr *)&_socket_addr, sizeof(_socket_addr)) == -1) 
    {
        close(_socket);
        throw std::runtime_error("Error\nServer init - joining socket failed.");
    }
    if (listen(_socket, 10) == -1)
    {
        close(_socket);
        throw std::runtime_error("Error\nServer init - listening socket failed.");
    }    
}

void    Server::run()
{
    socklen_t   socklen = sizeof(_socket_addr);
    while (true)
    {
        int client_socket = accept(_socket, (struct sockaddr*)&_socket_addr, &socklen);

        if (client_socket == -1)
            throw std::runtime_error("Error\nServer init - can't accept client.");

        Client  *client = new Client(client_socket);

        char buffer[1024];
        int bytes_read = read(client_socket, buffer, sizeof(buffer));
        if (bytes_read == -1) {
          perror("read");
          return;
        }
        std::cout << buffer << std::endl;
        _clients.insert(client);
    }    
}