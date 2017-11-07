#include "Instance.hpp"

#include <string>
#include <iostream>
#include <thread>

using namespace std;

Instance::Instance()
{
    sock = new MSocket;
}

Instance::~Instance()
{
    delete sock;
    delete loop;
}

void Instance::login()
{
    sock->init();

    //Login
    sock->Msend("PASS oauth:zmff7qlqdjxpqs54r3lf4ga5xhlr51");
    sock->Msend("NICK bot_of_all_trades");

    main_loop_thread = new thread(&Instance::main_loop, this);
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
	recv_string = sock->Mrecv();

	if(recv_string == "PING :tmi.twitch.tv")
	    sock->Msend("PONG :tmi.twitch.tv");
    }
    
}
