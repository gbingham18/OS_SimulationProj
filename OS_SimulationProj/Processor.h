#ifndef PROCESSOR_H_
#define PROCESSOR_H_
#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include "PCB.h"
using namespace std;

class Processor {
	public:
	Processor() {}
	void handleProcess(PCB process) {
		srand(time(NULL));
		for (int i = 0; i < process.eventList.size(); i++)
		{
			for (int j = 0; j < process.eventList.front(); j++)
			{
				int IO = rand() % 5 + 1;
				if (IO == 3)
				{
					handleIO(process);
				}
				process.eventList.front()--;
			}
		}
		//Move PCB to appropriate queue
	}

	void handleIO(PCB proc) {}

};

#endif