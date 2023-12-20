 #ifndef ERRIRC_HPP
#define ERRIRC_HPP

//--------------------------------------------------------------------------//
//                                - INCLUDES -                              //
//--------------------------------------------------------------------------//

# include <iostream>
# include <exception>

//--------------------------------------------------------------------------//
//                                 - CLASS -                                //
//--------------------------------------------------------------------------//

class ErrIrc
{
    public:
        class ErrIrcFormatException : public std::exception
        {
            const char *what() const throw()
            {
                return "Wrong format, please use a valid IP and Port.";
            }
        };

};

#endif