#ifndef USERSTATE_H
#define USERSTATE_H

#include "Message.hpp"
#include "Badges.hpp"

#include <string>

class USERSTATE: public Message
{
public:
    USERSTATE(std::string _raw_msg);
    ~USERSTATE() override;

    std::string getPrintString() override;

    void update(std::map<std::string, Channel*>* channel_list) override;

private:
    void print_contents();
    Badges* badges;
    std::string color;
    std::string display_name;
    std::string emote_sets;
    std::string mod;
    std::string subscriber;
    std::string user_type;
    std::string channel;
};

#endif
