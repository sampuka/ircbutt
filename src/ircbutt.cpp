#include <iostream>
#include <string>

#include "Instance.hpp"

using namespace std;

int main()
{
    string x;
    Instance irc;

    irc.login();
    irc.getCapabilities();
    
    cin >> x;

    irc.join("#starladder_cs_en");
    
    cin >> x;

    return 0;
}
3
