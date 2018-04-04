#include <iostream>
#include <string>
using namespace std;

class PCB {
    public:
    int PID;
    int Priority;
    int arrivalTime;
    int CPUbursttime;
    int IObursttime;
    string State;

    //To be calculated
    int currentTotalTime;
    int finalTotalTime;

	PCB(int ID, int Pr, int AT, int CPUburst, int IOburst)
    {
        PID = ID;
        Priority  = Pr;
        arrivalTime = AT;
        CPUbursttime = CPUburst;
		IObursttime = IOburst;
        currentTotalTime = 0;
    }

}