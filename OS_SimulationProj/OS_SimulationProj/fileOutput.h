#ifndef FILEOUTPUT_H_
#define FILEOUTPUT_H_
#include <iostream>
#include <string>
#include <fstream>
#include "Random.h"
using namespace std;

extern Random my_Rand;

void writeToFile()
{
	srand(time(NULL));

	int PID = 0;
	int arrivalTime = 0;
	int burstTime = 0;
	int priority = 0;
	vector <int> eventList;
	ofstream myfile;
	myfile.open("example.txt");
	for (int i = 0; i < 1000; i++)
	{
		PID++;
		arrivalTime = rand() % 1000;
		priority = rand() % 10 + 1;

		int numEvents = rand() % 5 + 1;
		for (int j = 0; j < numEvents; j++)
		{
			burstTime = rand() % 10 + 1;
			if (j % 2 == 0)
			{
				eventList.push_back(burstTime);
			}
			else
			{
				eventList.push_back(burstTime);
			}
		}
		myfile << PID << ' ' << arrivalTime << ' ' << priority;

		for (int k = 0; k < eventList.size(); k++)
		{
			myfile << ' ' << eventList[k];
		}
		myfile << "\n";
		eventList.clear();
	}
	myfile.close();
}

#endif