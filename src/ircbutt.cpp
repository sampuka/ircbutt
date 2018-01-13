#include <iostream>
#include <string>

#include "Instance.hpp"

using namespace std;

//#DEFINE VERBOSE 1

#define TARGET_CHANNEL "#doge_ow"

vector<string> login_files = {"bot_of_all_trades"
			      ///*
			      , "marilynjakbo", "lostthesea"
			      //*/
};

int main()
{
    vector<Instance*> instances;
    Instance* instance;
    for (string login_file : login_files)
    {
	instance = new Instance();
	instance->login("login_" + login_file + ".txt");
	instances.push_back(instance);
    }
    
    string x;
    cin >> x;

    for(Instance* instance : instances)
	instance->join(TARGET_CHANNEL);

    cin.ignore();

    while(1)
    {
	getline(cin, x, '\n');
	for(Instance* instance : instances)
	    instance->send_privmsg(x, TARGET_CHANNEL);
    }
    
    cin >> x;
    
    return 0;
}
