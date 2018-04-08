#ifndef FILEINPUT_H_
#define FILEINPUT_H_
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>
#include "PCB.h"
using namespace std;

vector<PCB> readFile(vector<PCB> processes) {
	ifstream myfile("processes.txt");
	if (!myfile.is_open())
	{
		cout << "File not open" << endl;
	}
	string line;
	vector<int> PCBproperties;
	vector<int> eventList;
	while (!myfile.eof())
	{
		getline(myfile, line);
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
		PCBproperties.clear();
		eventList.clear();
	}
	return processes;
};

#endif