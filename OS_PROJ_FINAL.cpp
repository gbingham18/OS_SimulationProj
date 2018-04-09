#include <iostream>
#include <queue>
#include "fileOutput.h"
#include "fileInput.h"
#include "PCB.h"
#include "FCFS.h"
#include "RR.h"
#include "SPN.h"
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

void calculateAveragesFCFS(FCFS fcfs)
{

	ofstream myFile("FCFS.txt", fstream::app);

	int sum = 0;
	double avg_resp = 0, avg_wait = 0, avg_turn = 0;

	for (int i = 0; i < fcfs.terminatedProcesses.size() - 1; i++)
	{
		sum += fcfs.terminatedProcesses[i].responseTime;
	}
	avg_resp = sum / fcfs.terminatedProcesses.size();
	cout << "Average Response Time FCFS: " << avg_resp << endl;

	for (int i = 0; i < fcfs.terminatedProcesses.size() - 1; i++)
	{
		sum += fcfs.terminatedProcesses[i].waitTime;
	}
	avg_wait = sum / fcfs.terminatedProcesses.size();
	cout << "Average Wait Time FCFS: " << avg_wait << endl;

	for (int i = 0; i < fcfs.terminatedProcesses.size() - 1; i++)
	{
		sum += fcfs.terminatedProcesses[i].turnaroundTime;
	}
	avg_turn = sum / fcfs.terminatedProcesses.size();
	cout << "Average Turnaround Time FCFS: " << avg_turn << endl;

	double through = (fcfs.CPUTime / fcfs.terminatedProcesses.size());

	cout << "FCFS Throughout: One process completed every " << through << " time units" << endl;
	cout << endl;

	myFile << avg_resp << "\t" << avg_turn << "\t" << avg_wait << "\t" << through << endl;
	myFile.close();
}

void calculateAveragesRR1(RoundRobin RR) {

	ofstream myFile("RR1.txt", fstream::app);

	int sum = 0;
	double avg_resp = 0, avg_wait = 0, avg_turn = 0;

	for (int i = 0; i < RR.terminatedProcesses.size() - 1; i++)
	{
		sum += RR.terminatedProcesses[i].responseTime;
	}
	avg_resp = sum / RR.terminatedProcesses.size();
	cout << "Average Response Time RR: " << avg_resp << endl;

	for (int i = 0; i < RR.terminatedProcesses.size() - 1; i++)
	{
		sum += RR.terminatedProcesses[i].waitTime;
	}
	avg_wait = sum / RR.terminatedProcesses.size();
	cout << "Average Wait Time RR: " << avg_wait << endl;

	for (int i = 0; i < RR.terminatedProcesses.size() - 1; i++)
	{
		sum += RR.terminatedProcesses[i].turnaroundTime;
	}
	avg_turn = sum / RR.terminatedProcesses.size();
	cout << "Average Turnaround Time RR: " << avg_turn << endl;

	double through = (RR.CPUTime / RR.terminatedProcesses.size());

	cout << "RR Throughout: One process completed every " << through << " time units" << endl;
	cout << endl;

	myFile << avg_resp << "\t" << avg_turn << "\t" << avg_wait << "\t" << through << endl;
	myFile.close();
}

void calculateAveragesRR2(RoundRobin RR) {

	ofstream myFile("RR2.txt", fstream::app);

	int sum = 0;
	double avg_resp = 0, avg_wait = 0, avg_turn = 0;

	for (int i = 0; i < RR.terminatedProcesses.size() - 1; i++)
	{
		sum += RR.terminatedProcesses[i].responseTime;
	}
	avg_resp = sum / RR.terminatedProcesses.size();
	cout << "Average Response Time RR: " << avg_resp << endl;

	for (int i = 0; i < RR.terminatedProcesses.size() - 1; i++)
	{
		sum += RR.terminatedProcesses[i].waitTime;
	}
	avg_wait = sum / RR.terminatedProcesses.size();
	cout << "Average Wait Time RR: " << avg_wait << endl;

	for (int i = 0; i < RR.terminatedProcesses.size() - 1; i++)
	{
		sum += RR.terminatedProcesses[i].turnaroundTime;
	}
	avg_turn = sum / RR.terminatedProcesses.size();
	cout << "Average Turnaround Time RR: " << avg_turn << endl;

	double through = (RR.CPUTime / RR.terminatedProcesses.size());

	cout << "RR Throughout: One process completed every " << through << " time units" << endl;
	cout << endl;

	myFile << avg_resp << "\t" << avg_turn << "\t" << avg_wait << "\t" << through << endl;
	myFile.close();
}

void calculateAveragesRR3(RoundRobin RR) {

	ofstream myFile("RR3.txt", fstream::app);

	int sum = 0;
	double avg_resp = 0, avg_wait = 0, avg_turn = 0;

	for (int i = 0; i < RR.terminatedProcesses.size() - 1; i++)
	{
		sum += RR.terminatedProcesses[i].responseTime;
	}
	avg_resp = sum / RR.terminatedProcesses.size();
	cout << "Average Response Time RR: " << avg_resp << endl;

	for (int i = 0; i < RR.terminatedProcesses.size() - 1; i++)
	{
		sum += RR.terminatedProcesses[i].waitTime;
	}
	avg_wait = sum / RR.terminatedProcesses.size();
	cout << "Average Wait Time RR: " << avg_wait << endl;

	for (int i = 0; i < RR.terminatedProcesses.size() - 1; i++)
	{
		sum += RR.terminatedProcesses[i].turnaroundTime;
	}
	avg_turn = sum / RR.terminatedProcesses.size();
	cout << "Average Turnaround Time RR: " << avg_turn << endl;

	double through = (RR.CPUTime / RR.terminatedProcesses.size());

	cout << "RR Throughout: One process completed every " << through << " time units" << endl;
	cout << endl;

	myFile << avg_resp << "\t" << avg_turn << "\t" << avg_wait << "\t" << through << endl;
	myFile.close();
}

void calculateAveragesRR4(RoundRobin RR) {

	ofstream myFile("RR4.txt", fstream::app);

	int sum = 0;
	double avg_resp = 0, avg_wait = 0, avg_turn = 0;

	for (int i = 0; i < RR.terminatedProcesses.size() - 1; i++)
	{
		sum += RR.terminatedProcesses[i].responseTime;
	}
	avg_resp = sum / RR.terminatedProcesses.size();
	cout << "Average Response Time RR: " << avg_resp << endl;

	for (int i = 0; i < RR.terminatedProcesses.size() - 1; i++)
	{
		sum += RR.terminatedProcesses[i].waitTime;
	}
	avg_wait = sum / RR.terminatedProcesses.size();
	cout << "Average Wait Time RR: " << avg_wait << endl;

	for (int i = 0; i < RR.terminatedProcesses.size() - 1; i++)
	{
		sum += RR.terminatedProcesses[i].turnaroundTime;
	}
	avg_turn = sum / RR.terminatedProcesses.size();
	cout << "Average Turnaround Time RR: " << avg_turn << endl;

	double through = (RR.CPUTime / RR.terminatedProcesses.size());

	cout << "RR Throughout: One process completed every " << through << " time units" << endl;
	cout << endl;

	myFile << avg_resp << "\t" << avg_turn << "\t" << avg_wait << "\t" << through << endl;
	myFile.close();
}

void calculateAveragesSPN(SPN spn) {

	ofstream myFile("SPN.txt", fstream::app);

	int sum = 0;
	double avg_resp = 0, avg_wait = 0, avg_turn = 0;

	for (int i = 0; i < spn.terminatedProcesses.size() - 1; i++)
	{
		sum += spn.terminatedProcesses[i].responseTime;
	}
	avg_resp = sum / spn.terminatedProcesses.size();
	cout << "Average Response Time SPN: " << avg_resp << endl;

	for (int i = 0; i < spn.terminatedProcesses.size() - 1; i++)
	{
		sum += spn.terminatedProcesses[i].waitTime;
	}
	avg_wait = sum / spn.terminatedProcesses.size();
	cout << "Average Wait Time SPN: " << avg_wait << endl;

	for (int i = 0; i < spn.terminatedProcesses.size() - 1; i++)
	{
		sum += spn.terminatedProcesses[i].turnaroundTime;
	}
	avg_turn = sum / spn.terminatedProcesses.size();
	cout << "Average Turnaround Time SPN: " << avg_turn << endl;

	double through = (spn.CPUTime / spn.terminatedProcesses.size());

	cout << "SPN Throughout: One process completed every " << through << " time units" << endl;
	cout << endl;

	myFile << avg_resp << "\t" << avg_turn << "\t" << avg_wait << "\t" << through << endl;
	myFile.close();
}

int main() {
	vector<PCB> processes;
	for (int i = 0; i < 100; i++) {
		writeToFile();
		processes = readFile(processes);

		cout << i + 1 << endl << endl;

		FCFS fcfs(processes);
		calculateAveragesFCFS(fcfs);

		RoundRobin RR1(processes, 2, 2, 2);
		calculateAveragesRR1(RR1);

		RoundRobin RR2(processes, 1, 2, 3);
		calculateAveragesRR2(RR2);

		RoundRobin RR3(processes, 2, 4, 6);
		calculateAveragesRR3(RR3);

		RoundRobin RR4(processes, 3, 6, 9);
		calculateAveragesRR4(RR4);

		SPN spn(processes);
		calculateAveragesSPN(spn);

		processes.clear();
	}

	return 0;
}