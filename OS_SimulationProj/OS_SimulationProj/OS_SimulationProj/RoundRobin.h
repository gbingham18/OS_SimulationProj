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
	vector<PCB> ReadyQueue1;
	vector<PCB> ReadyQueue2;
	vector<PCB> ReadyQueue3;
	std::priority_queue<PCB> BlockedQueue;
	vector<PCB> terminatedProcesses;
	int timeQuantum1;
	int timeQuantum2;
	int timeQuantum3;
	int CPUTime;

	RoundRobin(vector<PCB> processes, int tq1, int tq2, int tq3) {
		CPUTime = 1;
		timeQuantum1 = tq1;
		timeQuantum2 = tq2;
		timeQuantum3 = tq3;
		JobQueue = processes;
		sortProcesses();
		while (!(ReadyQueue1.size() == 0 && ReadyQueue2.size() == 0 && ReadyQueue3.size() == 0 && JobQueue.size() == 0 && BlockedQueue.size() == 0))
		{
			addToReadyQueue1();
			handleProcess(ReadyQueue1.back(), timeQuantum1);
			handleProcess(ReadyQueue2.back(), timeQuantum2);
			handleProcess(ReadyQueue3.back(), timeQuantum3);
			ReadyQueue1.pop_back();
			contextSwitch();
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

	void addToReadyQueue1() {
		//cout << "here0" << endl;
		while (JobQueue.size() != 0 && JobQueue[JobQueue.size() - 1].arrivalTime <= CPUTime)
		{
			//cout << "H" << endl;
			ReadyQueue1.push_back(JobQueue.back());
			//cout << "I" << endl;
			JobQueue.pop_back();
			//cout << "J" << endl;
		}
		contextSwitch();
	}

	void contextSwitch() {
		CPUTime += 1;
	}

	void handleProcess(PCB &process, int tq, int queue) {
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
				CPUTime += min(process.eventList.back(), tq);
				process.eventList.back() -= tq;
				if (process.eventList.back() <= 0) {
					process.eventList.pop_back();
					if (process.eventList.size() > 0)
					{
						if (queue == 1) { ReadyQueue2.push_back(process); }
						else { ReadyQueue3.push_back(process); }
					}
				}
				else {
					if (queue == 1) { ReadyQueue2.push_back(process); }
					else { ReadyQueue3.push_back(process); }
				}
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

	int min(int a, int b) {
		if (a < b) { return a; }
		else { return b; }
	}
};