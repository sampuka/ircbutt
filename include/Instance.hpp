#include <string>
#include <thread>
#include "MSocket.hpp"

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
    std::thread *main_loop_thread;
    std::string login_name;
    std::string login_OAuth;
    MSocket *sock;
};
