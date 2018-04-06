#include <iostream>
#include <vector>
#include "fileOutput.h"
#include "fileInput.h"
#include "PCB.h"
#include "FCFS.h"
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;


int main() {
	vector<PCB> processes;
	//writeToFile();
	processes = readFile(processes);
	FCFS fcfs(processes);
	//for (int i = 0; i < processes.size(); i++)
	//{
	//	cout << "ID: " << processes[i].PID << " AT: " << processes[i].arrivalTime << " Priority: " << processes[i].Priority;
	//	cout << " EventList: ";
	//	for (int j = 0; j < processes[i].eventList.size(); j++)
	//	{
	//		cout << processes[i].eventList[j] << " ";
	//	}
	//	cout << endl;
	//}

	return 0;
}