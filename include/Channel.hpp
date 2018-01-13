#ifndef CHANNEL_H
#define CHANNEL_H

#include "Badges.hpp"

#include <string>

class Channel
{
public:
    Channel(std::string channel_name);
    ~Channel();

    std::string getBroadcaster_lang();
    void setBroadcaster_lang(std::string _broadcaster_lang);

    std::string getEmote_only();
    void setEmote_only(std::string _emote_only);

    std::string getFollowers_only();
    void setFollowers_only(std::string _followers_only);

    std::string getMercury();
    void setMercury(std::string _mercury);

    std::string getR9k();
    void setR9k(std::string _r9k);

    std::string getRoom_id();
    void setRoom_id(std::string _room_id);

    std::string getSlow();
    void setSlow(std::string _slow);

    std::string getSubs_only();
    void setSubs_only(std::string _subs_only);

    std::string getChannel();

    Badges* getBadges();
    void setBadges(std::string badgeStr);

    std::string getColor();
    void setColor(std::string _color);
    
    std::string getDisplay_name();
    void setDisplay_name(std::string _display_name);
    
    std::string getMod();
    void setMod(std::string _mod);
    
    std::string getEmote_sets();
    void setEmote_sets(std::string _emote_sets);
    
    std::string getSubscriber();
    void setSubscriber(std::string _subscriber);
    
    std::string getUser_type();
    void setUser_type(std::string _user_type);

private:
    //Channel settings
    std::string broadcaster_lang;
    std::string emote_only;
    std::string followers_only;
    std::string mercury;
    std::string r9k;
    std::string room_id;
    std::string slow;
    std::string subs_only;
    std::string channel;

    //User settings for channel
    Badges* badges;
    std::string color;
    std::string display_name;
    std::string emote_sets;
    std::string mod;
    std::string subscriber;
    std::string user_type;
};

#endif
