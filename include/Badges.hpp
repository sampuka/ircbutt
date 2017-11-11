#ifndef BADGES_H
#define BADGES_H

#include <string>

class Badges
{
public:
    Badges(std::string _raw_str);
    ~Badges();

    std::string getStr();

    bool isAdmin();
    bool isBits();
    int getBits();
    bool isBroadcaster();
    bool isGlobal_mod();
    bool isModerator();
    bool isSubscriber();
    int getSubMonths();
    bool isStaff();
    bool isTurbo();
    bool isPremium(); //NOT IN DOCUMENTATION???
    bool isPartner();
    bool isGlhf_pledge();
    
private:
    std::string raw_str;

    int admin;
    int bits;
    int broadcaster;
    int global_mod;
    int moderator;
    int subscriber;
    int staff;
    int turbo;
    int premium;
    int partner;
    int glhf_pledge;
};

#endif
