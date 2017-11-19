#ifndef MESSAGE_H
#define MESSAGE_H

#include "Channel.hpp"

#include <string>
#include <map>

#include "Channel.hpp"

//https://tools.ietf.org/html/rfc1459.html#section-4
enum class MessageType
{
    PASS,
	NICK,
	USER,
	SERVER,
	OPER,
	QUIT,
	SQUIT,
	JOIN,
	PART,
	MODE,
	TOPIC,
	NAMES,
	LIST,
	INVITE,
	KICK,
	VERSION,
	STATS,
	LINKS,
	TIME,
	CONNECT,
	TRACE,
	ADMIN,
	INFO,
	PRIVMSG,
	NOTICE,
	WHO,
	WHOIS,
	WHOWAS,
	KILL,
	PING,
	PONG,
	ERROR,
	AWAY,
	REHASH,
	RESTART,
	SUMMON,
	USERS,
	WALLOPS,
	USERHOST,
	ISON,
	
    //Twitch specific message types (I think)
	USERNOTICE,
	USERSTATE,
	ROOMSTATE,
	HOSTTARGET,
	CLEARCHAT //confirm ?? 
	};

class Message
{
public:
    //Message();
    virtual ~Message() = 0;
    virtual std::string should_reply();
    virtual std::string getSendString(Channel* chan);
    virtual std::string getPrintString() = 0;

    virtual void update(std::map<std::string, Channel*>* channel_list);

    MessageType getMessageType();
    std::string getMsg();

protected:
    std::string raw_msg;
    MessageType msg_type;
};

#endif
