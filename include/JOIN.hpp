#ifndef JOIN_H
#define JOIN_H

#include "Message.hpp"

#include <string>

class JOIN: public Message
{
public:
    JOIN(std::string _raw_msg);
    ~JOIN() override;
    
    std::string getPrintString() override;

private:
    std::string username;
    std::string channel;
};

#endif
