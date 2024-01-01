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
        class ErrServerInit : public std::exception
        {
            const char *what() const throw()
            {
                return "Error";
            }
        };

};

#endif