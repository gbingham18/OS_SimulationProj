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
	vector<PCB> ReadyQueue;
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
			//cout << "JobQueue size: " << JobQueue.size() << endl;
			if (ReadyQueue.size() != 0) {
				handleProcess(ReadyQueue.back());
				ReadyQueue.pop_back();
				contextSwitch();
			}
			else {
				CPUTime++;
			}
		}
	}

	void sortProcesses() {
		//cout << "here" << endl;
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
		//cout << "here0" << endl;
		while(JobQueue.size() != 0 && JobQueue[JobQueue.size() - 1].arrivalTime <= CPUTime)
		{
				//cout << "H" << endl;
				ReadyQueue.push_back(JobQueue.back());
				//cout << "I" << endl;
				JobQueue.pop_back();
				//cout << "J" << endl;
		}
		contextSwitch();
		while (BlockedQueue.size() != 0 && BlockedQueue.top().endBlockedTime <= CPUTime)
		{
			//cout << "L" << endl;
			ReadyQueue.push_back(BlockedQueue.top());
			//cout << "M" << BlockedQueue.size() <<endl;
			BlockedQueue.pop();
			//cout << "N" << endl;
		}
		contextSwitch();
	}

	void contextSwitch() {
		CPUTime += 1;
	}

	void handleProcess(PCB &process) {
		//cout << "here2" << endl;
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
				//cout << "here3" << endl;
				CPUTime += process.eventList.back();
				process.eventList.pop_back();
			}
		}
		if (process.eventList.size() == 0)
		{
			//cout << "Terminating Process: " << process.PID << endl;
			terminatedProcesses.push_back(process);
		}
	}

	void handleIO(PCB &proc, int IOburst) {
		//cout << "here5" << endl;
		proc.endBlockedTime = CPUTime + IOburst;
		BlockedQueue.push(proc);
		
	}

};

#endif