#ifndef PING_H
#define PING_H

#include "Message.hpp"

#include <string>
#include <ctime>

class PING: public Message
{
public:
    PING(std::string _raw_msg);
    ~PING() override;

    std::string should_reply() override;
    std::string getSendString(Channel* chan) override;
    std::string getPrintString() override;
    
private:
    time_t t;
};

#endif
