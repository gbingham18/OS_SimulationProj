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
				int IOburst = process.eventList.back();
				process.eventList.pop_back();
				handleIO(process, CPUTime, IOburst);
				break;
			}
			else
			{
				CPUTime += process.eventList.back();
				process.eventList.pop_back();
			}
		}
		if (process.eventList.size() == 0)
		{
			fcfs.terminatedProcesses.push_back(process);
		}
	}

	void handleIO(PCB &proc, int &CPUTime, int IOburst) {
		proc.endBlockedTime = CPUTime;
		fcfs.BlockedQueue.push(proc);
	}

};

#endif