#ifndef PCB_H_
#define PCB_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PCB {
public:
	int PID;
	int arrivalTime;
	int Priority;
	int endBlockedTime;
	vector<int> eventList;

	//Only referenced in RoundRobin.h
	int currQueue;

	//Only referenced in SPN.h
	int processTime;
	bool IO;

	//To be calculated
	int responseTime;
	int waitTime;
	int turnaroundTime;

	//Used to calculate wait time
	int RQTime;

	PCB(int ID, int AT, int Pr, vector<int> EL)
	{
		PID = ID;
		arrivalTime = AT;
		Priority = Pr;
		eventList = EL;
		responseTime = -1;
		waitTime = 0;
		turnaroundTime = 0;
		endBlockedTime = -1;
		processTime = 0;
		IO = true;
	}

	void calculateProcessTime() {
		for (int i = 0; i < eventList.size(); i++) {
			processTime += eventList[i];
		}
	}

	bool operator<(const PCB &other) const
	{
		if (IO)
		{
			if (endBlockedTime > other.endBlockedTime) {
				return true;
			}
			else if (endBlockedTime == other.endBlockedTime && Priority > other.Priority) {
				return true;
			}
			else {
				return false;
			}
		}
		else
		{
			if (processTime > other.processTime) {
				return true;
			}
			else if (endBlockedTime == other.endBlockedTime && Priority > other.Priority) {
				return true;
			}
			else {
				return false;
			}
		}
	}

};

#endif