# ircbutt
Attempt to make a proper bot for Twitch that handles all types of messages, OO-style in C++ (name subject to change)

# Accumulated list of places where the documentation is missing or wrong
<b>PRIVMSG with Tags:</b>

1. 'display-name' is not empty even if never set (I think)
2. No mention of optional parameter emote-only
3. No mention of optional parameter sent-ts

<b>Badges:</b>

1. No mention of following badges: 'premium', 'partner' or 'glhf-pledge'
2. Would be nice to know 'subscriber' can be '0' even for subscribers

# Troubleshooting:
1. If you cant compile make sure the folder /src/obj/ exists