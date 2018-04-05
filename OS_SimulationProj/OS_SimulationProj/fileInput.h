#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "../OS_SimulationProj/PCB.h"
using namespace std;

vector<PCB> readFile(vector<PCB> processes) {
	ifstream myfile("example.txt");
	string line;
	vector<int> PCBproperties;
	vector<int> eventList;
	while (getline(myfile, line))
	{
		istringstream iss(line);
		for (string s; iss >> s;)
		{
			stringstream geek(s);
			int x = 0;
			geek >> x;
			PCBproperties.push_back(x);
		}
		for (int i = 3; i < PCBproperties.size(); i++)
		{
			eventList.push_back(PCBproperties[i]);
		}
		PCB process(PCBproperties[0], PCBproperties[1], PCBproperties[2], eventList);
		processes.push_back(process);
	}
	return processes;
}
