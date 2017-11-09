#include "PING.hpp"

using namespace std;

PING::PING(string _raw_msg)
{
    msg_type = MessageType::PING;
    raw_msg = _raw_msg;
    t = time(NULL);
}

PING::~PING()
{
}

string PING::getSendString()
{
    return "PONG :tmi.twitch.tv";
}

string PING::getPrintString()
{
    return "PONG";
}
