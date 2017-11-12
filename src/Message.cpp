#include "Message.hpp"

#include <string>
#include <iostream>

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

void Message::update(map<string, Channel*>* channel_list)
{
    cout << "SHOULD NOT BE CALLED Message.cpp:24" << endl;
}
