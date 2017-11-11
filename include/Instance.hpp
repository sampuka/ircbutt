#ifndef INSTANCE_H
#define INSTANCE_H

#include "MSocket.hpp"
#include "Message.hpp"

#include <string>
#include <thread>
#include <vector>

class Instance
{
public:
    Instance();
    ~Instance();
    void login();
    void join(std::string channel);
    void getCapabilities();
    
private:
    void main_loop();
    void interpret_msg(std::string msg);
    void handle_loop();
    std::vector<Message*> msg_list;
    bool list_busy; //Bool value to indicate a thread is working on the list. To avoid multiple threads working on the list at the same time.
    std::thread *main_loop_thread;
    std::thread *handle_loop_thread;
    std::string login_name;
    std::string login_OAuth;
    MSocket *sock;
};

#endif
