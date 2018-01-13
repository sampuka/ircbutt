#include "USERSTATE.hpp"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

USERSTATE::USERSTATE(string _raw_msg)
{
    msg_type = MessageType::USERSTATE;
    raw_msg = _raw_msg;

    stringstream ss(raw_msg);
    string s;

    getline(ss, s, '=');
    getline(ss, s, ';');
    badges = new Badges(s);

    getline(ss, s, '=');
    getline(ss, s, ';');
    color = s;

    getline(ss, s, '=');
    getline(ss, s, ';');
    display_name = s;

    getline(ss, s, '=');
    getline(ss, s, ';');
    emote_sets = s;

    getline(ss, s, '=');
    getline(ss, s, ';');
    mod = s;

    getline(ss, s, '=');
    getline(ss, s, ';');
    subscriber = s;

    getline(ss, s, '=');
    getline(ss, s, ' ');
    user_type = s;

    getline(ss, s, ' ');
    getline(ss, s, ' ');
    getline(ss, s, ' ');
    channel = s;

    //print_contents();
}

USERSTATE::~USERSTATE()
{
    delete badges;
}
/*
string USERSTATE::getSendString()
{
    return "";
}
*/
string USERSTATE::getPrintString()
{
    string to_return = "---\nUserstate for " + display_name + " in " + channel + ": ";
    if(emote_sets == "0")
	to_return += "\nNo emotes";
    else
	to_return += "\nWith emotes = " + emote_sets;

    if(mod == "1")
	to_return += "\nIs mod";
    else
	to_return += "\nIs not mod";

    if(subscriber == "1")
	to_return += "\nIs subscriber";
    else
	to_return += "\nIs not subscriber";
	
    if(user_type == "")
	to_return += "\nNo user-type";
    else
	to_return += "\nUser-type: " + user_type;

    return to_return + "\n---";
}

void USERSTATE::update(map<string, Channel*>* channel_list)
{
    //cout << "USERSTATE::update called" << endl;
    Channel* chan = (*channel_list)[channel];

    chan->setBadges(badges->getStr());
    chan->setColor(color);
    chan->setDisplay_name(display_name);
    chan->setEmote_sets(emote_sets);
    chan->setMod(mod);
    chan->setSubscriber(subscriber);
    chan->setUser_type(user_type);
}

void USERSTATE::print_contents()
{
    cout << "\nbadges = " << badges->getStr() << " = " << badges->getBadgeStr()
	 << "\ncolor = " << color
	 << "\ndisplay-name = " << display_name
	 << "\nemote-sets = " << emote_sets
	 << "\nmod = " << mod
	 << "\nsubscriber = " << subscriber
	 << "\nuser-type = " << user_type
	 << "\nchannel = " << channel
	 << endl;
}
