#ifndef ROUNDROBIN_H_
#define ROUNDROBIN_H_
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
#include "PCB.h"

class RoundRobin {
public:
	vector<PCB> JobQueue;
	queue<PCB> ReadyQueue1;
	queue<PCB> ReadyQueue2;
	queue<PCB> ReadyQueue3;
	std::priority_queue<PCB> BlockedQueue;
	vector<PCB> terminatedProcesses;
	int timeQuantum1;
	int timeQuantum2;
	int timeQuantum3;
	int CPUTime;
	int CS;

	RoundRobin(vector<PCB> processes, int tq1, int tq2, int tq3) {
		CS = 0;
		CPUTime = 1;
		timeQuantum1 = tq1;
		timeQuantum2 = tq2;
		timeQuantum3 = tq3;
		JobQueue = processes;
		sortProcesses();
		while (!(ReadyQueue1.size() == 0 && ReadyQueue2.size() == 0 && ReadyQueue3.size() == 0 && JobQueue.size() == 0 && BlockedQueue.size() == 0))
		{
			addToReadyQueue1();
			if (!ReadyQueue1.empty()) {
				ReadyQueue1.front().waitTime += (CPUTime - ReadyQueue1.front().RQTime);
				handleProcess(ReadyQueue1.front(), timeQuantum1, 1);
				ReadyQueue1.pop();
				contextSwitch();
			}
			if (!ReadyQueue2.empty()) {
				ReadyQueue2.front().waitTime += (CPUTime - ReadyQueue2.front().RQTime);
				handleProcess(ReadyQueue2.front(), timeQuantum2, 2);
				ReadyQueue2.pop();
				contextSwitch();
			}
			if (!ReadyQueue3.empty()) {
				ReadyQueue3.front().waitTime += (CPUTime - ReadyQueue3.front().RQTime);
				handleProcess(ReadyQueue3.front(), timeQuantum3, 3);
				ReadyQueue3.pop();
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

	void addToReadyQueue1() {
		while (JobQueue.size() != 0 && JobQueue[JobQueue.size() - 1].arrivalTime <= CPUTime)
		{
			ReadyQueue1.push(JobQueue.back());
			ReadyQueue1.back().RQTime = CPUTime;
			JobQueue.pop_back();
		}
		contextSwitch();
		while (BlockedQueue.size() != 0 && BlockedQueue.top().endBlockedTime <= CPUTime)
		{
			if (BlockedQueue.top().currQueue == 1) { 
				ReadyQueue1.push(BlockedQueue.top());
				ReadyQueue1.back().RQTime = CPUTime;
			}
			else if (BlockedQueue.top().currQueue == 2) { 
				ReadyQueue2.push(BlockedQueue.top());
				ReadyQueue2.back().RQTime = CPUTime;
			}
			else if (BlockedQueue.top().currQueue == 3) { 
				ReadyQueue3.push(BlockedQueue.top());
				ReadyQueue3.back().RQTime = CPUTime;
			}
			BlockedQueue.pop();
		}

	}

	void contextSwitch() {
		CPUTime += 1;
		CS++;
	}

	void handleProcess(PCB &process, int tq, int queue) {
		bool IO = false;
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
					IO = true;
					int IOburst = process.eventList.back();
					process.eventList.pop_back();
					handleIO(process, IOburst, queue);
					break;
				}
				else
				{
					CPUTime += min(process.eventList.back(), tq);
					process.eventList.back() -= tq;
					if (process.eventList.back() <= 0) {
						process.eventList.pop_back();
					}
				}
			}
			else
			{				
				CPUTime += min(process.eventList.back(), tq);
				process.eventList.back() -= tq;
				if (process.eventList.back() <= 0) {
					process.eventList.pop_back();
				}
			}
		}
		if (process.eventList.size() == 0)
		{
			process.turnaroundTime = (CPUTime - process.arrivalTime);
			terminatedProcesses.push_back(process);
		}
		if (!IO)
		{
			if (process.eventList.size() > 0 && queue == 1) { 
				ReadyQueue2.push(process);
				ReadyQueue2.back().RQTime = CPUTime;
			}
			else if (process.eventList.size() > 0) {
				ReadyQueue3.push(process);
				ReadyQueue3.back().RQTime = CPUTime;
			}
		}
	}

	void handleIO(PCB &proc, int IOburst, int q) {
		proc.endBlockedTime = CPUTime + IOburst;
		proc.currQueue == q;
		BlockedQueue.push(proc);
	}

	int min(int a, int b) {
		if (a < b) { return a; }
		else { return b; }
	}
};

#endif