#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;

void writeToFile()
{
	srand(time(NULL));

	int PID = 0;
	int arrivalTime = 0;
	int burstTime = 0;
	int priority = 0;
	vector <string> burstList;
	string burstType[2] = { "CPU", "IO" };
	ofstream myfile;
	myfile.open("example.txt");
	for (int i = 0; i < 1000; i++)
	{
		PID++;
		arrivalTime = rand() % 10 + 1;
		int numBursts = rand() % 5 + 1;
		for (int j = 0; j < numBursts; j++)
		{
			burstTime = rand() % 10 + 1;
			string s = to_string(burstTime);
			if (j % 2 == 0)
			{
				burstList.push_back("CPU " + s);
			}
			else
			{
				burstList.push_back("IO " + s);
			}
		}
		myfile << PID << ' ' << arrivalTime << ' ';

		for (int k = 0; k < burstList.size(); k++)
		{
			myfile << burstList[k] << ' ';
		}
		myfile << "\n";
		burstList.clear();
	}
	myfile.close();
}
