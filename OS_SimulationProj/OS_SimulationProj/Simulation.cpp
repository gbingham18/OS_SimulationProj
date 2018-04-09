#include <iostream>
#include <queue>
#include "fileOutput.h"
#include "fileInput.h"
#include "PCB.h"
#include "FCFS.h"
#include "RoundRobin.h"
#include "SPN.h"
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

void calculateAveragesFCFS(FCFS fcfs)
{
	int sum = 0;
	double average = 0;

	for (int i = 0; i < fcfs.terminatedProcesses.size() - 1; i++)
	{
		sum += fcfs.terminatedProcesses[i].responseTime;
	}
	average = sum / fcfs.terminatedProcesses.size();
	cout << "Average Response Time FCFS: " << average << endl;

	sum = 0;
	average = 0;

	for (int i = 0; i < fcfs.terminatedProcesses.size() - 1; i++)
	{
		sum += fcfs.terminatedProcesses[i].waitTime;
	}
	average = sum / fcfs.terminatedProcesses.size();
	cout << "Average Wait Time FCFS: " << average << endl;

	sum = 0;
	average = 0;

	for (int i = 0; i < fcfs.terminatedProcesses.size() - 1; i++)
	{
		sum += fcfs.terminatedProcesses[i].turnaroundTime;
	}
	average = sum / fcfs.terminatedProcesses.size();
	cout << "Average Turnaround Time FCFS: " << average << endl;

	cout << "FCFS Throughout: One process completed every " << (fcfs.CPUTime / fcfs.terminatedProcesses.size()) << " time units" << endl;
	cout << endl;
}

void calculateAveragesRR(RoundRobin RR) {
	int sum = 0;
	double average = 0;

	for (int i = 0; i < RR.terminatedProcesses.size() - 1; i++)
	{
		sum += RR.terminatedProcesses[i].responseTime;
	}
	average = sum / RR.terminatedProcesses.size();
	cout << "Average Response Time RR: " << average << endl;

	sum = 0;
	average = 0;

	for (int i = 0; i < RR.terminatedProcesses.size() - 1; i++)
	{
		sum += RR.terminatedProcesses[i].waitTime;
	}
	average = sum / RR.terminatedProcesses.size();
	cout << "Average Wait Time RR: " << average << endl;

	sum = 0;
	average = 0;

	for (int i = 0; i < RR.terminatedProcesses.size() - 1; i++)
	{
		sum += RR.terminatedProcesses[i].turnaroundTime;
	}
	average = sum / RR.terminatedProcesses.size();
	cout << "Average Turnaround Time RR: " << average << endl;

	cout << "RR Throughout: One process completed every " << (RR.CPUTime / RR.terminatedProcesses.size()) << " time units" << endl;
	cout << endl;
}

void calculateAveragesSPN(SPN spn) {
	int sum = 0;
	double average = 0;

	for (int i = 0; i < spn.terminatedProcesses.size() - 1; i++)
	{
		sum += spn.terminatedProcesses[i].responseTime;
	}
	average = sum / spn.terminatedProcesses.size();
	cout << "Average Response Time SPN: " << average << endl;

	sum = 0;
	average = 0;

	for (int i = 0; i < spn.terminatedProcesses.size() - 1; i++)
	{
		sum += spn.terminatedProcesses[i].waitTime;
	}
	average = sum / spn.terminatedProcesses.size();
	cout << "Average Wait Time SPN: " << average << endl;

	sum = 0;
	average = 0;

	for (int i = 0; i < spn.terminatedProcesses.size() - 1; i++)
	{
		sum += spn.terminatedProcesses[i].turnaroundTime;
	}
	average = sum / spn.terminatedProcesses.size();
	cout << "Average Turnaround Time SPN: " << average << endl;

	cout << "RR Throughout: One process completed every " << (spn.CPUTime / spn.terminatedProcesses.size()) << " time units" << endl;
	cout << endl;
}

int main() {
	vector<PCB> processes;
	//writeToFile();
	processes = readFile(processes);
	FCFS fcfs(processes);
	RoundRobin RR(processes, 1, 2, 3);
	SPN spn(processes);

	calculateAveragesFCFS(fcfs);
	calculateAveragesRR(RR);
	calculateAveragesSPN(spn);

	return 0;
}