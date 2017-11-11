#include "Badges.hpp"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Badges::Badges(string _raw_str)
{
    raw_str = _raw_str;
    
    admin = 0;
    bits = 0;
    broadcaster = 0;
    global_mod = 0;
    moderator = 0;
    subscriber = -1;
    staff = 0;
    turbo = 0;
    premium = 0;
    partner = 0;

    stringstream ss(raw_str);
    string s;
    int slen = 0;

/*
    string regex_str = "([a-z]+)\\/([0-9]+)";
    
    regex re(regex_str, std::regex_constants::basic);
    smatch match;

    regex retest("([0-9]+)", std::regex_constants::basic);
    smatch matchtest;
    string match_str = "056";
    regex_match(match_str, matchtest, retest);
    cout << "regex test = " << matchtest[0].str() << endl;
*/

    while(ss.good())
    {
	getline(ss, s, ',');
	slen = s.length();

	if(slen == 0)
	    break;

	int slashpos = s.find('/');
	//cout << "slashpos = " << slashpos << endl;

	string badge_str = s.substr(0, slashpos);
	string version_str = s.substr(slashpos+1, slen-slashpos);

	//cout << "badge_str = " << badge_str << " version_str = " << version_str << endl;
	
        if(badge_str == "admin")
	{
	    admin = stoi(version_str);
	}
        else if(badge_str == "bits")
	{
	    bits = stoi(version_str);
	}
        else if(badge_str == "broadcaster")
	{
	    broadcaster = stoi(version_str);
	}
        else if(badge_str == "global_mod")
	{
	    global_mod = stoi(version_str);
	}
        else if(badge_str == "moderator")
	{
	    moderator = stoi(version_str);
	}
        else if(badge_str == "subscriber")
	{
	    subscriber = stoi(version_str);
	    //cout << "subscriber matched with " << subMonths << " months" << endl;
	}
        else if(badge_str == "staff")
	{
	    staff = stoi(version_str);
	}
        else if(badge_str == "turbo")
	{
	    turbo = stoi(version_str);
	}
        else if(badge_str == "premium")
	{
	    premium = stoi(version_str);
	}
        else if(badge_str == "partner")
	{
	    partner = stoi(version_str);
	}
        else if(badge_str == "glhf-pledge")
	{
	    glhf_pledge = stoi(version_str);
	}
	else
	{
	    cout << "didn't match badge \"" << badge_str << "\"" << endl;
	}

/*
	cout << "trying to regex match on \"" << s << "\" with regex \"" << regex_str << "\"" << endl;
        regex_match(s, match, re);
	
	ssub_match badge_match = match[1];
	ssub_match version_match = match[2];
	cout << "regex: badge_match = " << badge_match.str() << " version_match = " << version_match.str() << endl;
*/
	
    }


/*
    admin = (raw_str.find("admin/1") != string::npos);
    bits = (raw_str.find("bits/1") != string::npos);
    broadcaster = (raw_str.find("broadcaster/1") != string::npos);;
    global_mod = (raw_str.find("global_mod/1") != string::npos);
    moderator = (raw_str.find("moderator/1") != string::npos);
    subscriber = (raw_str.find("subscriber/1") != string::npos);
    staff = (raw_str.find("staff/1") != string::npos);
    turbo = (raw_str.find("turbo/1") != string::npos);
    premium = (raw_str.find("premium/1") != string::npos);
*/
}

Badges::~Badges()
{
}

string Badges::getStr()
{
    return raw_str;
}

string Badges::getBadgeStr()
{
    string to_return = "";
    if(isAdmin())
	to_return += "[A]";
    if(isBits())
    {
	to_return += "[Bits";
	to_return += to_string(getBits());
	to_return += "]";
    }
    if(isBroadcaster())
	to_return += "[B]";
    if(isGlobal_mod())
	to_return += "[G]";
    if(isModerator())
	to_return += "[M]";
    if(isSubscriber())
    {
	to_return += "[Sub";
	int submonths = getSubMonths();
	if(submonths != 0)
	    to_return += to_string(submonths);
	to_return += "]";
    }
    if(isStaff())
	to_return += "[S]";
    if(isTurbo())
	to_return += "[T]";
    if(isPremium())
	to_return += "[P]";
    if(isPartner())
	to_return += "[Partner]";
    if(isGlhf_pledge())
	to_return += "[GLHF]";
    
    if(to_return != "")
	to_return += " ";


    return to_return;
}

bool Badges::isAdmin()
{
    return admin == 1;
}

bool Badges::isBits()
{
    return bits > 0;
}

int Badges::getBits()
{
    return bits;
}

bool Badges::isBroadcaster()
{
    return broadcaster == 1;
}

bool Badges::isGlobal_mod()
{
    return global_mod == 1;
}

bool Badges::isModerator()
{
    return moderator == 1;
}

bool Badges::isSubscriber()
{
    return subscriber >= 0;
}

int Badges::getSubMonths()
{
    if(isSubscriber())
	return subscriber;
    else
	return -1;
}

bool Badges::isStaff()
{
    return staff == 1;
}

bool Badges::isTurbo()
{
    return turbo == 1;
}

bool Badges::isPremium()
{
    return premium == 1;
}

bool Badges::isPartner()
{
    return partner == 1;
}

bool Badges::isGlhf_pledge()
{
    return glhf_pledge == 1;
}
