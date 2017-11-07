//https://tools.ietf.org/html/rfc1459.html#section-4

enum MessageType
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
    ISON
};

class Message
{
public:
    //Message();
    //~Message();
    MessageType getMessageType();

protected:
    MessageType msg_type;
};
