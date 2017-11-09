#include "JOIN.hpp"

#include <string>
#include <sstream>

using namespace std;

JOIN::JOIN(string _raw_msg)
{
    msg_type = MessageType::JOIN;
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

    //cout << username << " " << channel << endl;
}

JOIN::~JOIN()
{
}

string JOIN::getSendString()
{
    return "";
}

string JOIN::getPrintString()
{
    return username + " joined " + channel;
}
