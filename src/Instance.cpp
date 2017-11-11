#include "Instance.hpp"

#include "PING.hpp"
#include "PRIVMSG.hpp"
#include "JOIN.hpp"
#include "PART.hpp"
#include "MODE.hpp"
#include "USERSTATE.hpp"

#include <string>
#include <sstream>
#include <iostream>
#include <thread>

using namespace std;

Instance::Instance()
{
    sock = new MSocket;
    msg_list = {}; //Can delete if confirmed that vectors start empty
    list_busy = 0;
}

Instance::~Instance()
{
    delete sock;
    delete main_loop_thread;
    delete handle_loop_thread;
}

void Instance::login()
{
    sock->init();

    //Login
    sock->Msend("PASS oauth:zmff7qlqdjxpqs54r3lf4ga5xhlr51");
    sock->Msend("NICK bot_of_all_trades");

    main_loop_thread = new thread(&Instance::main_loop, this);
    handle_loop_thread = new thread(&Instance::handle_loop, this);
}

void Instance::join(string channel)
{
    sock->Msend("JOIN " + channel);
}

void Instance::getCapabilities()
{
    sock->Msend("CAP REQ :twitch.tv/membership");
    sock->Msend("CAP REQ :twitch.tv/tags");
    sock->Msend("CAP REQ :twitch.tv/commands");
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
	list_busy = 1;
    
    
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

	else
	    cout << "!!!\"" << s << "\"" << endl;

	list_busy = 0;
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
	    list_busy = 1;
	    msg = msg_list.back();
	    msg_list.pop_back();
	    list_busy = 0;
	    
	    switch(msg->getMessageType())
	    {
	    case MessageType::PING:
		sock->Msend(msg->getSendString());
		cout << msg->getPrintString() << endl;
		break;

	    case MessageType::PRIVMSG:
		sock->Msend(msg->getSendString());
		cout << msg->getPrintString() << endl;
		break;

	    case MessageType::JOIN:
		sock->Msend(msg->getSendString());
		cout << msg->getPrintString() << endl;
		break;

	    case MessageType::PART:
		sock->Msend(msg->getSendString());
		cout << msg->getPrintString() << endl;
		break;

	    case MessageType::MODE:
		sock->Msend(msg->getSendString());
		cout << msg->getPrintString() << endl;
		break;

	    case MessageType::USERSTATE:
		sock->Msend(msg->getSendString());
		cout << msg->getPrintString() << endl;
		break;

	    default:
		break;
	    }

	    delete msg;
	}
    }
}

