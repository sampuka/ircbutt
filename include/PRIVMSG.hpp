#ifndef PRIVMSG_H
#define PRIVMSG_H

#include "Message.hpp"
#include "Badges.hpp"

#include <string>

class PRIVMSG: public Message
{
public:
    PRIVMSG(std::string _raw_msg);
    ~PRIVMSG();
    std::string getSendString() override;
    std::string getPrintString() override;

private:
    void print_contents();
    Badges* badges;
    std::string bits;
    std::string color;
    std::string display_name;
    std::string emote_only;
    std::string emotes;
    std::string id;
    std::string mod;
    std::string room_id;
    std::string sent_ts;
    std::string subscriber;
    std::string tmi_sent_ts;
    std::string turbo;
    std::string user_id;
    std::string user_type;
    std::string username;
    std::string channel;
    std::string msg;
};

#endif
