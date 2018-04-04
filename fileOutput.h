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
	string burstType[2] = {"CPU", "IO"};
	ofstream myfile;
	myfile.open("example.txt");
	for (int i = 0; i < 1000; i++)
	{
		PID++;
		srand(time(NULL));
		arrivalTime = rand() % 10 + 1;
		string burstList[] = { "" };
		int numBursts = rand() % 5 + 1;
		for (int i = 0; i < numBursts; i++)
		{
			burstTime = rand() % 10 + 1;
			string s = to_string(burstTime);
			if (i % 2 == 0)
			{
				burstList[i] = "CPU " + s;
			}
			else
			{
				burstList[i] = "IO " + s;
			}
		}
		myfile << PID << arrivalTime;

		for (int i = 0; i < sizeof(burstList); i++)
		{
			myfile << burstList[i];
		}
		myfile << "\n";
	}
	myfile.close();
}
