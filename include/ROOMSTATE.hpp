#ifndef ROOMSTATE_H
#define ROOMSTATE_H

#include "Message.hpp"

#include <string>

class ROOMSTATE: public Message
{
public:
    ROOMSTATE(std::string _raw_msg);
    ~ROOMSTATE() override;

    std::string getSendString() override;
    std::string getPrintString() override;

private:
    std::string broadcaster_lang;
    std::string emote_only;
    std::string followers_only;
    std::string mercury;
    std::string r9k;
    std::string room_id;
    std::string slow;
    std::string subs_only;
    std::string channel;

};

#endif
