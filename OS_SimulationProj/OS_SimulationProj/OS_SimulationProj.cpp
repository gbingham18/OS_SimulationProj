#include <iostream>
#include <vector>
#include "fileOutput.h"
#include "fileInput.h"
#include "PCB.h"
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;


int main() {
	vector<PCB> processes;
	writeToFile();
	processes = readFile(processes);

	return 0;
}
