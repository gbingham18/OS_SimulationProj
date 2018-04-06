#ifndef PROCESSOR_H_
#define PROCESSOR_H_
#include <iostream>
#include "PCB.h"
#include "FCFS.h"
#include <cstdlib>
#include <ctime>
using namespace std;


class FCFSProcessor {
public:
	FCFS fcfs;
	FCFSProcessor(FCFS &F) {
		fcfs = F;
	}
	void handleProcess(PCB &process, int &CPUTime) {
		if (process.responseTime < 0)
		{
			process.responseTime = CPUTime;
		}
		srand(time(NULL));
		while (process.eventList.size() > 0)
		{
			int IO = rand() % 5 + 1;
			if (IO == 3)
			{
				handleIO(process);
				break;
			}
			else
			{
				CPUTime += process.eventList.back();
			}
		}
		if (process.eventList.size() == 0)
		{
			fcfs.terminatedProcesses.push_back(process);
		}
	}

	void handleIO(PCB &proc) {
		fcfs.BlockedQueue.push(proc);
	}

	void contextSwitch(int &CPUTime) {
		CPUTime += 1;
	}

};

#endif