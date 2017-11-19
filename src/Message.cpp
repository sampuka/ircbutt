#include "Message.hpp"

#include <string>
#include <iostream>

using namespace std;

Message::~Message()
{
}

string Message::should_reply()
{
    return "";
}

string Message::getSendString(Channel* chan)
{
    return "";
}

MessageType Message::getMessageType()
{
    return msg_type;
}

string Message::getMsg()
{
    return raw_msg;
}

void Message::update(map<string, Channel*>* channel_list)
{
    cout << "SHOULD NOT BE CALLED Message.cpp:24" << endl;
}
