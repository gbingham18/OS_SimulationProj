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
	string State;

	//To be calculated
	int responseTime;

	PCB(int ID, int AT, int Pr, vector<int> EL)
	{
		PID = ID;
		arrivalTime = AT;
		Priority = Pr;
		eventList = EL;
		responseTime = -1;
		State = "Start";
		endBlockedTime = -1;
	}

	bool operator<(const PCB &other) const
	{
		if (endBlockedTime >= other.endBlockedTime) {
			return true;
		}
		else
			return false;
	}

};

#endif