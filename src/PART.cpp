#include "PART.hpp"

#include <string>
#include <sstream>

using namespace std;

PART::PART(string _raw_msg)
{
    msg_type = MessageType::PART;
    raw_msg = _raw_msg;

    stringstream ss(raw_msg);
    string s;
    
    getline(ss, s, '@');
    getline(ss, s, '.');
    username = s;

    getline(ss, s, ' ');
    getline(ss, s, ' ');
    getline(ss, s, ' ');
    channel = s;
}

PART::~PART()
{
}

string getSendString()
{
    return "";
}

string getPrintString()
{
    return username + " left " + channel;
}
