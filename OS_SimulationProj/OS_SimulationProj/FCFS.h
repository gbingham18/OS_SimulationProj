#ifndef FCFS_H_
#define FCFS_H_
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
#include "PCB.h"
using namespace std;

class FCFS {
	public:
	vector<PCB> JobQueue;
	queue<PCB> ReadyQueue;
	std::priority_queue<PCB> BlockedQueue;
	vector<PCB> terminatedProcesses;
	int CPUTime;
	FCFS() {}
	FCFS(vector<PCB> processes) {
		CPUTime = 1;
		JobQueue = processes;
		sortProcesses();
		while (!(ReadyQueue.size() == 0 && JobQueue.size() == 0 && BlockedQueue.size() == 0))
		{
			addToReadyQueue();
			if (ReadyQueue.size() != 0) {
				ReadyQueue.front().waitTime += (CPUTime - ReadyQueue.front().RQTime);
				handleProcess(ReadyQueue.front());
				ReadyQueue.pop();
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
		while(JobQueue.size() != 0 && JobQueue[JobQueue.size() - 1].arrivalTime <= CPUTime)
		{
				ReadyQueue.push(JobQueue.back());
				ReadyQueue.back().RQTime = CPUTime;
				JobQueue.pop_back();
		}
		contextSwitch();
		while (BlockedQueue.size() != 0 && BlockedQueue.top().endBlockedTime <= CPUTime)
		{
			ReadyQueue.push(BlockedQueue.top());
			ReadyQueue.back().RQTime = CPUTime;
			BlockedQueue.pop();
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
		BlockedQueue.push(proc);
	}

};

#endif