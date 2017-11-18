#include <iostream>
#include <string>

#include "Instance.hpp"

using namespace std;

vector<string> login_files = {"bot_of_all_trades"};

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
	instance->join("#followgrubby");
    
    cin >> x;

    return 0;
}
