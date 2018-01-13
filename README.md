# ircbutt
Attempt to make a proper bot for Twitch that handles all types of messages, OO-style in C++ (name subject to change)

# Usage
Login information for account <name> should be in login_<name>.txt. First line should be <name> and second line should be the oauth which can be found (Hint: Google).
As of now, the login files to be used are defined in the login_files variable in ircbutt.cpp

# Accumulated list of places where the documentation is missing or wrong
<b>PRIVMSG with Tags:</b>

1. 'display-name' is not empty even if never set (I think)
2. No mention of optional parameters 'emote-only' and 'sent-ts'

<b>ROOMSTATE:</b>

1. Where do I find possible values for 'broadcaster-languages'?
2. No mention of the following parameters 'emote-only', 'followers-only', 'mercury' (what is this even) and 'room-id'
3. Seriously what the fuck is 'mercury'?

<b>Badges:</b>

1. No mention of following badges: 'premium', 'partner' or 'glhf-pledge'
2. Would be nice to know 'subscriber' can be '0' even for subscribers

# Troubleshooting:
1. If you cant compile make sure the folder /src/obj/ exists