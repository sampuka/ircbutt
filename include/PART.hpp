#ifndef PART_H
#define PART_H

#include "Message.hpp"

#include <string>

class PART: public Message
{
public:
    PART(std::string);
    ~PART() override;
    std::string getSendString() override;
    std::string getPrintString() override;
    
private:
    std::string username;
    std::string channel;
};

#endif
