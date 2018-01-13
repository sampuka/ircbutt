#ifndef INSTANCE_H
#define INSTANCE_H

#include "MSocket.hpp"
#include "Message.hpp"
#include "Channel.hpp"

#include <string>
#include <thread>
#include <vector>
#include <map>

class Instance
{
public:
    Instance();
    ~Instance();
    void login(std::string login_file);
    void join(std::string channel);
    void getCapabilities();

    void send_privmsg(std::string msg, std::string channel);
    void send_privmsg(std::string msg, Channel* chan);
    
private:
    void main_loop();
    void interpret_msg(std::string msg);

    void handle_loop();

    void reply_for(Message* msg);

    std::vector<Message*> msg_list;
    bool list_busy; //Bool value to indicate a thread is working on the list. To avoid multiple threads working on the list at the same time.

    std::map<std::string, Channel*> channel_list;

    std::thread *main_loop_thread;
    std::thread *handle_loop_thread;
    MSocket *sock;
};

#endif
