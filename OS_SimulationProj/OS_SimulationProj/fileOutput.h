#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;

void writeToFile()
{
	int PID = 0;
	int arrivalTime = 0;
	int burstTime = 0;
	int priority = 0;
	ofstream myfile;
	myfile.open("example.txt");
	for (int i = 0; i < 1000; i++)
	{
		PID++;
		srand(time(NULL));
		arrivalTime = rand() % 1000;
		priority = rand() % 10 + 1;
		int eventList[] = {0};
		int numEvents = rand() % 5 + 1;
		for (int i = 0; i < numEvents; i++)
		{
			burstTime = rand() % 10 + 1;
			if (i % 2 == 0)
			{
				eventList[i] = burstTime;
			}
			else
			{
				eventList[i] = burstTime;
			}
		}
		myfile << PID << " " << arrivalTime << " " << priority;

		for (int i = 0; i < sizeof(eventList); i++)
		{
			myfile << " " << eventList[i];
		}
		myfile << "\n";
	}
	myfile.close();
}
