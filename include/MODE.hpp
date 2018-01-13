#ifndef MODE_H
#define MODE_H

#include "Message.hpp"

#include <string>

class MODE: public Message
{
public:
    MODE(std::string _raw_msg);
    ~MODE() override;
    
    std::string getPrintString();

private:
    std::string channel;
    std::string mode;
    std::string username;
};

#endif
