#include "MODE.hpp"

#include <string>
#include <sstream>

using namespace std;

MODE::MODE(string _raw_msg)
{
    msg_type = MessageType::MODE;
    raw_msg = _raw_msg;

    stringstream ss(raw_msg);
    string s;
    
    getline(ss, s, ' ');
    getline(ss, s, ' ');
    getline(ss, s, ' ');
    channel = s;

    getline(ss, s, ' ');
    mode = s;

    getline(ss, s, ' ');
    username = s;
}

MODE::~MODE()
{
}
/*
string MODE::getSendString()
{
    return "";
}
*/
string MODE::getPrintString()
{
    return username + " got " + mode + " in " + channel;
}
