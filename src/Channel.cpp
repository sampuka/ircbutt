#include "Channel.hpp"

//#include <iostream>

using namespace std;

Channel::Channel(std::string channel_name)
{
    channel = channel_name;

    //Set everything to default values, it is expected that as soon as the channel is joined a ROOMSTATE and USERSTATE is received so it's updated properly

    broadcaster_lang = "";
    emote_only = "0";
    followers_only = "-1";
    mercury = "0";
    r9k = "0";
    slow = "0";
    subs_only = "0";

    badges = NULL;
    color = "";
    display_name = "";
    emote_sets = "0";
    mod = "0";
    subscriber = "0";
    user_type = "";
}

Channel::~Channel()
{
    delete badges;
}

string Channel::getBroadcaster_lang()
{
    return broadcaster_lang;
}

void Channel::setBroadcaster_lang(string _broadcaster_lang)
{
    broadcaster_lang = _broadcaster_lang;
}

string Channel::getEmote_only()
{
    return emote_only;
}

void Channel::setEmote_only(std::string _emote_only)
{
    emote_only = _emote_only;
}

string Channel::getFollowers_only()
{
    return followers_only;
}

void Channel::setFollowers_only(std::string _followers_only)
{
    followers_only = _followers_only;
}

string Channel::getMercury()
{
    return mercury;
}

void Channel::setMercury(std::string _mercury)
{
    mercury = _mercury;
}

string Channel::getR9k()
{
    return r9k;
}

void Channel::setR9k(std::string _r9k)
{
    r9k = _r9k;
}

string Channel::getRoom_id()
{
    //cout << "Channel::getRoom_id called" << endl;
    return room_id;
}

void Channel::setRoom_id(std::string _room_id)
{
    room_id = _room_id;
}

string Channel::getSlow()
{
    return slow;
}

void Channel::setSlow(std::string _slow)
{
    slow = _slow;
}

string Channel::getSubs_only()
{
    return subs_only;
}

void Channel::setSubs_only(std::string _subs_only)
{
    subs_only = _subs_only;
}

string Channel::getChannel()
{
    return channel;
}

Badges* Channel::getBadges()
{
    return badges;
}

void Channel::setBadges(string badgeStr)
{
    delete badges;
    badges = new Badges(badgeStr);
}

string Channel::getColor()
{
    return color;
}

void Channel::setColor(string _color)
{
    color = _color;
}
    
string Channel::getDisplay_name()
{
    return display_name;
}

void Channel::setDisplay_name(string _display_name)
{
    display_name = _display_name;
}
    
string Channel::getMod()
{
    return mod;
}

void Channel::setMod(string _mod)
{
    mod = _mod;
}
    
string Channel::getEmote_sets()
{
    return emote_sets;
}

void Channel::setEmote_sets(string _emote_sets)
{
    emote_sets = _emote_sets;
}
    
string Channel::getSubscriber()
{
    return subscriber;
}

void Channel::setSubscriber(string _subscriber)
{
    subscriber = _subscriber;
}
   
string Channel::getUser_type()
{
    return user_type;
}

void Channel::setUser_type(string _user_type)
{
    user_type = _user_type;
}
