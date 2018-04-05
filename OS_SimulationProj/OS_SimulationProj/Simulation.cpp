#include <iostream>
#include <vector>
#include "fileOutput.h"
#include "fileInput.h"
#include "PCB.h"
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "Random.h"
using namespace std;

Random my_Rand;

int main() {
	vector<PCB> processes;
	writeToFile();
	processes = readFile(processes);

	return 0;
}
