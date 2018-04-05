#ifndef FCFS_H_
#define FCFS_H_
#include <iostream>
#include <vector>
#include "PCB.h"
#include "Processor.h"
using namespace std;

extern Random my_Rand;

class FCFS {
	vector<PCB> JobQueue;
	vector<PCB> ReadyQueue;
	vector<PCB> BlockedQueue;
	vector<PCB> terminatedProcesses;
	Processor Processor;
	FCFS(vector<PCB> processes) {
		JobQueue = processes;
		sortProcesses();
		updateQueues();
		Processor.handleProcess(ReadyQueue.back());
		ReadyQueue.pop_back();
	}

	void sortProcesses() {
		bool isSorted = false;
		while (isSorted == false)
		{
			isSorted = true;
			for (int i = 0; i < JobQueue.size(); i++)
			{
				if (JobQueue[i].arrivalTime > JobQueue[i + 1].arrivalTime)
				{
					isSorted = false;
					PCB temp = JobQueue[i];
					JobQueue[i] = JobQueue[i + 1];
					JobQueue[i + 1] = temp;
				}
			}
		}
	}

	void updateQueues() {
		while (JobQueue[JobQueue.size() - 1].arrivalTime == 0)
		{
			ReadyQueue.push_back(JobQueue.back());
			JobQueue.pop_back();
		}
	}
};

#endif