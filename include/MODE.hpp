#include "Message.hpp"

#include <string>

class MODE: public Message
{
public:
    MODE(std::string _raw_msg);
    ~MODE() override;
    std::string getSendString();
    std::string getPrintString();

private:
    std::string channel;
    std::string mode;
    std::string username;
};
