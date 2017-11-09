#include "PRIVMSG.hpp"

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

PRIVMSG::PRIVMSG(string _raw_msg)
{
    msg_type = MessageType::PRIVMSG;
    raw_msg = _raw_msg;

    //these variables are optional in the message so I set them to nothing first in case they don't show up;
    bits = ""; 
    sent_ts = "";
    emote_only = "";

    stringstream ss(raw_msg);

    string s;

    getline(ss, s, '=');
    getline(ss, s, ';'); 
    badges = s;

    getline(ss, s, '=');

    //cout << "bits? \"" << s << "\"" << endl;

    if(s == "bits")
    {
	getline(ss, s, ';');
	bits = s;
	getline(ss, s, '=');
    }

    getline(ss, s, ';');
    color = s;

    getline(ss, s, '=');
    getline(ss, s, ';');   
    display_name = s;

    getline(ss, s, '=');

    //cout << "emote-only? \"" << s << "\"" << endl;

    if(s == "emote-only")
    {
	getline(ss, s, ';');
	emote_only = s;
	getline(ss, s, '=');
    }

    getline(ss, s, ';');
    emotes = s;

    getline(ss, s, '=');
    getline(ss, s, ';');
    id = s;

    getline(ss, s, '=');
    getline(ss, s, ';'); 
    mod = s;

    getline(ss, s, '=');
    getline(ss, s, ';'); 
    room_id = s;
    
    getline(ss, s, '=');

    //cout << "sent-ts? \"" << s << "\"" << endl;

    if(s == "sent-ts")
    {
	//cout << "sent-ts if trig" << endl;
	getline(ss, s, ';');
	sent_ts = s;
	getline(ss, s, '=');
    }

    getline(ss, s, ';'); 
    subscriber = s;
    
    getline(ss, s, '=');
    getline(ss, s, ';'); 
    tmi_sent_ts = s;
    
    getline(ss, s, '=');
    getline(ss, s, ';'); 
    turbo = s;
    
    getline(ss, s, '=');
    getline(ss, s, ';'); 
    user_id = s;
    
    getline(ss, s, '=');
    getline(ss, s, ' '); 
    user_type = s;

    getline(ss, s, ':');
    getline(ss, s, '!'); 
    username = s;

    getline(ss, s, ' ');
    getline(ss, s, ' '); 
    getline(ss, s, ' ');
    channel = s;

    getline(ss, s, ':');
    getline(ss, s, '\n');
    msg = s;

    //print_contents();
}

PRIVMSG::~PRIVMSG()
{
}

string PRIVMSG::getSendString()
{
    //Do stuff here
    return "";
}

string PRIVMSG::getPrintString()
{
    return display_name + ": " + msg;
}

void PRIVMSG::print_contents()
{
    
    cout << "badges = " << badges 
	 << "\nbits = " << bits 
	 << "\ncolor = " << color 
	 << "\ndisplay-name = " << display_name 
	 << "\nemote-only = " << emote_only
	 << "\nemotes = " << emotes 
	 << "\nid = " << id 
	 << "\nmod = " << mod 
	 << "\nroom-id = " << room_id 
	 << "\nsent-ts = " << sent_ts 
	 << "\nsubscriber = " << subscriber 
	 << "\ntmi-sent-ts = " << tmi_sent_ts 
	 << "\nturbo = " << turbo 
	 << "\nuser-id = " << user_id 
	 << "\nuser-type = " << user_type 
	 << "\nusername = " << username
	 << "\nchannel = " << channel 
	 << "\nmsg = " << msg 
	 << endl;
}
