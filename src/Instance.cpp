#include "Instance.hpp"
#include "Channel.hpp"

#include "PING.hpp"
#include "PRIVMSG.hpp"
#include "JOIN.hpp"
#include "PART.hpp"
#include "MODE.hpp"
#include "USERSTATE.hpp"
#include "ROOMSTATE.hpp"

#include <string>
#include <sstream>
#include <iostream>
#include <thread>
#include <fstream>

using namespace std;

Instance::Instance()
{
    sock = new MSocket;
    msg_list = {}; //Can delete if confirmed that vectors start empty
    list_busy = false;
}

Instance::~Instance()
{
    delete sock;
    delete main_loop_thread;
    delete handle_loop_thread;
}

void Instance::login(string login_file)
{
    sock->init();

    //Open login file
    ifstream ifile;
    string oauth;
    string name;
    
    ifile.open(login_file);
    //Error if file doesn't open/exist
    
    getline(ifile, name);
    getline(ifile, oauth);

    //Login
    sock->Msend("PASS " + oauth);
    sock->Msend("NICK " + name);

    main_loop_thread = new thread(&Instance::main_loop, this);
    handle_loop_thread = new thread(&Instance::handle_loop, this);
}

void Instance::join(string channel)
{
    sock->Msend("JOIN " + channel);
    channel_list[channel] = new Channel(channel);
    getCapabilities();
}

void Instance::getCapabilities()
{
    sock->Msend("CAP REQ :twitch.tv/membership");
    sock->Msend("CAP REQ :twitch.tv/tags");
    sock->Msend("CAP REQ :twitch.tv/commands");
}

//Should return error value etc.
void Instance::send_privmsg(string msg, string channel)
{
    Channel* chan = channel_list[channel];

    //Should check for ability to msg

    sock->Msend("PRIVMSG " + channel + " :" + msg);
}

void Instance::send_privmsg(string msg, Channel* chan)
{
    sock->Msend("PRIVMSG " + chan->getChannel() + " :" + msg);
}

void Instance::main_loop()
{
    string recv_string;

    while(true)
    {
	while(recv_string == "")
	    recv_string = sock->Mrecv();
	
	interpret_msg(recv_string);
	recv_string = "";
    }
}

void Instance::interpret_msg(string msg)
{
    
    stringstream ss(msg);
    string s;
    while(ss.good())
    {	
	getline(ss, s, '\n');

	if(s == "")
	    return;
	
	s.pop_back();

	
	while(list_busy)
	    ;
	list_busy = true;
    
    
	if(s == "PING :tmi.twitch.tv")
	    msg_list.push_back(new PING(s));

	else if(s.find(".tmi.twitch.tv PRIVMSG ") != string::npos) //Lazy way of detecting PRIVMSG
	    msg_list.push_back(new PRIVMSG(s));

	else if(s.find(".tmi.twitch.tv JOIN ") != string::npos)
	    msg_list.push_back(new JOIN(s));

	else if(s.find(".tmi.twitch.tv PART ") != string::npos)
	    msg_list.push_back(new PART(s));

        else if(s.find(":jtv MODE ") != string::npos)
	    msg_list.push_back(new MODE(s));
	
	else if (s.find(":tmi.twitch.tv USERSTATE ") != string::npos)
	    msg_list.push_back(new USERSTATE(s));
	
	else if (s.find(":tmi.twitch.tv ROOMSTATE ") != string::npos)
	    msg_list.push_back(new ROOMSTATE(s));

	else
	    cout << "!!!\"" << s << "\"" << endl;

	list_busy = false;
    }
}

void Instance::handle_loop()
{
    Message* msg = NULL;

    while(1)
    {
	if(msg_list.size() > 0)
	{
	    while(list_busy)
		;
	    list_busy = true;
	    msg = msg_list.back();
	    msg_list.pop_back();
	    list_busy = false;
	    
	    switch(msg->getMessageType())
	    {
	    case MessageType::PING:
		reply_for(msg);
		cout << msg->getPrintString() << endl;
		break;

	    case MessageType::PRIVMSG:
		//sock->Msend(msg->getSendString());
		cout << msg->getPrintString() << endl;
		break;

	    case MessageType::JOIN:
		//sock->Msend(msg->getSendString());
		cout << msg->getPrintString() << endl;
		break;

	    case MessageType::PART:
		//sock->Msend(msg->getSendString());
		cout << msg->getPrintString() << endl;
		break;

	    case MessageType::MODE:
		//sock->Msend(msg->getSendString());
		cout << msg->getPrintString() << endl;
		break;

	    case MessageType::USERSTATE:
		//sock->Msend(msg->getSendString());
		cout << msg->getPrintString() << endl;
		msg->update(&channel_list);

		//cout << "channel: " << channel_list["#alkaizerx"]->getDisplay_name() << endl;
		//cout << "My badges: " << channel_list["#alkaizerx"]->getBadges()->getBadgeStr() << endl;
		break;

	    case MessageType::ROOMSTATE:
		//sock->Msend(msg->getSendString());
		cout << msg->getPrintString() << endl;
		msg->update(&channel_list);
		
/*
		cout << "channel: " << channel_list["#alkaizerx"]->getBroadcaster_lang() << endl;
		cout << "channel: " << channel_list["#alkaizerx"]->getRoom_id() << endl;
*/
		break;

	    default:
		break;
	    }

	    delete msg;
	}
    }
}

void Instance::reply_for(Message* msg)
{
    string channel = msg->should_reply();
    if(channel == "")
	;
    
    else if(channel == "to server")
        sock->Msend(msg->getSendString(NULL));
    
    else
    {
        Channel *chan = channel_list[channel];
	send_privmsg(msg->getSendString(chan), chan);
    }
}
