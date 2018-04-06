#ifndef FCFS_H_
#define FCFS_H_
#include <iostream>
#include <vector>
#include <queue>
#include "PCB.h"
#include "FCFSProcessor.h"
using namespace std;

class FCFS {
	public:
	vector<PCB> JobQueue;
	vector<PCB> ReadyQueue;
	std::priority_queue<PCB> BlockedQueue;
	vector<PCB> terminatedProcesses;
	FCFSProcessor Processor;
	int CPUTime;
	FCFS(vector<PCB> processes) {
		FCFSProcessor CPU(this);
		Processor = CPU;
		CPUTime = 1;
		JobQueue = processes;
		sortProcesses();
		while (JobQueue.size() != 0)
		{
			addToReadyQueue();
			Processor.handleProcess(ReadyQueue.back());
			ReadyQueue.pop_back();
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
		while (JobQueue[JobQueue.size() - 1].arrivalTime <= CPUTime)
		{
			ReadyQueue.push_back(JobQueue.back());
			JobQueue.pop_back();
		}
		contextSwitch();
		while (BlockedQueue.top() <= CPUTime)
		{
			ReadyQueue.push_back(BlockedQueue.top())
			BlockedQueue.pop();
		}
	}

	void contextSwitch() {
		CPUTime += 1;
	}

};

#endif