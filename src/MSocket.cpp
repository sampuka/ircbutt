#include "MSocket.hpp"

#include <string>
#include <iostream>
#include <string.h>

using namespace std;

MSocket::MSocket()
{
}

MSocket::~MSocket()
{
}

int MSocket::init()
{
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if((getaddrinfo("irc.chat.twitch.tv", "6667", &hints, &res)) != 0)
    {
	cout << "getaddrinfo() failed" << endl;
	return -1;
    }
    
    if((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1)
    {
	cout << "socket() failed" << endl;
	return -2;
    };

    if(connect(sockfd, res->ai_addr, res->ai_addrlen) != 0)
    {
	cout << "connect() failed" << endl;
	return -3;
    }

    return 0;
}

int MSocket::Msend(string msg)
{
    cout << "sending: \"" << msg <<'\"' <<  endl;
    msg += "\r\n";
    //cout << strlen(msg.c_str()) << msg << msg.length() << endl;
    send(sockfd, msg.c_str(), msg.length(), 0);

    return 0; //should check for errors
}

string MSocket::Mrecv()
{
    //string to_return = "";

    int bytes_read = recv(sockfd, recv_buffer, 99950, 0);
    //to_return = recv_buffer;

    /*
    while(to_return.substr(bytes_read-2, 2) != "\r\n")
    {
	cout << "!!!" << recv_buffer << endl;
	cout << "##################################### " << to_return.substr(to_return.length()-2, 2) << endl;
	bytes_read = recv(sockfd, recv_buffer, 1000, 0);
	cout << "to_return " << to_return.length() << " -> ";
	to_return += recv_buffer;
	cout << to_return.length() << endl;
    }
    */

    //to_return.pop_back();
    //to_return.pop_back();
    
    recv_buffer[bytes_read] = '\0';
	
    //cout << "recieved: \"" << recv_buffer << '\"' << endl;;
    return recv_buffer;
}
