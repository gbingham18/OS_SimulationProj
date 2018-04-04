#include <iostream>
#include <queue>
#include "PCB.h"
using namespace std;

class JobQueue {
	queue<PCB> JobPool;
	queue<PCB> ReadyQueue;
	queue<PCB> IOWaiting;


};