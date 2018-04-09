#ifndef SPN_H_
#define SPN_H_
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
#include "PCB.h"
using namespace std;

class SPN {
public:
	vector<PCB> JobQueue;
	std::priority_queue<PCB> ReadyQueue;
	std::priority_queue<PCB> BlockedQueue;
	vector<PCB> terminatedProcesses;
	int CPUTime;
	SPN() {}
	SPN(vector<PCB> processes) {
		CPUTime = 1;
		JobQueue = processes;
		sortProcesses();
		while (!(ReadyQueue.size() == 0 && JobQueue.size() == 0 && BlockedQueue.size() == 0))
		{
			addToReadyQueue();
			if (ReadyQueue.size() != 0) {
				PCB proc = ReadyQueue.top();
				proc.waitTime += (CPUTime - ReadyQueue.top().RQTime);
				ReadyQueue.pop();
				handleProcess(proc);
				contextSwitch();
			}
			else {
				CPUTime++;
			}
		}
	}

	void sortProcesses() {
		bool isSorted = false;
		while (isSorted == false)
		{
			isSorted = true;
			for (int i = 0; i < JobQueue.size() - 1; i++)
			{
				JobQueue[i].IO = false;
				if (JobQueue[i].arrivalTime < JobQueue[i + 1].arrivalTime)
				{
					isSorted = false;
					PCB temp = JobQueue[i];
					JobQueue[i] = JobQueue[i + 1];
					JobQueue[i + 1] = temp;
				}
			}
		}
	}

	void addToReadyQueue() {
		while (JobQueue.size() != 0 && JobQueue[JobQueue.size() - 1].arrivalTime <= CPUTime)
		{
			JobQueue.back().RQTime = CPUTime;
			ReadyQueue.push(JobQueue.back());
			JobQueue.pop_back();
		}
		contextSwitch();
		while (BlockedQueue.size() != 0 && BlockedQueue.top().endBlockedTime <= CPUTime)
		{
			PCB proc = BlockedQueue.top();
			BlockedQueue.pop();
			proc.IO = false;
			proc.RQTime = CPUTime;
			ReadyQueue.push(proc);
		}
		contextSwitch();
	}

	void contextSwitch() {
		CPUTime += 1;
	}

	void handleProcess(PCB &process) {
		if (process.responseTime < 0)
		{
			process.responseTime = CPUTime;
		}
		srand(time(NULL));
		while (process.eventList.size() > 0)
		{
			if (process.eventList.size() > 1)
			{
				int IO = rand() % 5 + 1;
				if (IO == 3)
				{
					int IOburst = process.eventList.back();
					process.eventList.pop_back();
					handleIO(process, IOburst);
					break;
				}
				else
				{
					CPUTime += process.eventList.back();
					process.eventList.pop_back();
				}
			}
			else
			{
				CPUTime += process.eventList.back();
				process.eventList.pop_back();
			}
		}
		if (process.eventList.size() == 0)
		{
			process.turnaroundTime = (CPUTime - process.arrivalTime);
			terminatedProcesses.push_back(process);
		}
	}

	void handleIO(PCB &proc, int IOburst) {
		proc.endBlockedTime = CPUTime + IOburst;
		proc.IO = true;
		BlockedQueue.push(proc);
	}

};

#endif