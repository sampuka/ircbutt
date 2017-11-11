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

    irc.join("#ppomodoli");
    
    cin >> x;

    return 0;
}
