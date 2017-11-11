#include "ROOMSTATE.hpp"

#include <string>
#include <sstream>

using namespace std;

ROOMSTATE::ROOMSTATE(string _raw_msg)
{
    msg_type = MessageType::ROOMSTATE;
    raw_msg = _raw_msg;

    stringstream ss(raw_msg);
    string s;

    getline(ss, s, '=');
    getline(ss, s, ';');
    broadcaster_lang = s;

    getline(ss, s, '=');
    getline(ss, s, ';');
    emote_only = s;

    getline(ss, s, '=');
    getline(ss, s, ';');
    followers_only = s;

    getline(ss, s, '=');
    getline(ss, s, ';');
    mercury = s;

    getline(ss, s, '=');
    getline(ss, s, ';');
    r9k = s;

    getline(ss, s, '=');
    getline(ss, s, ';');
    room_id = s;

    getline(ss, s, '=');
    getline(ss, s, ';');
    slow = s;

    getline(ss, s, '=');
    getline(ss, s, ' ');
    subs_only = s;

    getline(ss, s, ' ');
    getline(ss, s, ' ');
    getline(ss, s, ' ');
    channel = s;
}

ROOMSTATE::~ROOMSTATE()
{
}

string ROOMSTATE::getSendString()
{
    return "";
}

string ROOMSTATE::getPrintString()
{
    string to_return = "---\nRoomstate for " + channel;

    if(broadcaster_lang == "")
	to_return += "\nBroadcaster language not set";
    else
	to_return += "\nBroadcaster language: " + broadcaster_lang;

    if(emote_only == "0")
	to_return += "\nNot emote only";
    else
	to_return += "\nEmote only";

    if(followers_only == "-1")
	to_return += "\nNot followers only";
    else
	to_return += "\nFollowers only";

    if(mercury == "0")
	to_return += "\n'mercury' = 0";
    else
	to_return += "\n'mercury' = " + mercury + "!!!!!!!!!!!!!";

    if(r9k == "0")
	to_return += "\nr9k is off";
    else
	to_return += "\nr9k is on!";

    to_return += "\nRoom-id = " + room_id;

    if(slow == "0")
	to_return += "\nNot in slow mode";
    else
	to_return += "\nSlow mode: " + slow + " seconds";

    if(subs_only == "0")
	to_return += "\nNot subs only";
    else
	to_return += "\nSubs only";

    return to_return + "\n---";
}
