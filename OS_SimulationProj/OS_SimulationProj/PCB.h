#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PCB {
    public:
    int PID;
	int arrivalTime;
    int Priority;
	vector<int> eventList;
    string State;

    //To be calculated
	int currentRunTime;

	PCB(int ID, int AT, int Pr, vector<int> EL)
    {
        PID = ID;
		arrivalTime = AT;
        Priority  = Pr;
		eventList = EL;
        currentRunTime = 0;
		State = "Start";
    }

}