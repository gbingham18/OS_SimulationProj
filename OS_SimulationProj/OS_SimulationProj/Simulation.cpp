#include <iostream>
#include <vector>
#include "fileOutput.h"
#include "fileInput.h"
#include "PCB.h"
using namespace std;

int main() {
	vector<PCB> processes;
	writeToFile();
	processes = readFile(processes);
}
