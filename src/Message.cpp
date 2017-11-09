#include "Message.hpp"

#include <string>

using namespace std;

Message::~Message()
{
}

MessageType Message::getMessageType()
{
    return msg_type;
}

string Message::getMsg()
{
    return raw_msg;
}
