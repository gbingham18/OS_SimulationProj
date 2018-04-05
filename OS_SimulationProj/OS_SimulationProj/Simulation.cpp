#include <iostream>
#include <vector>
#include "fileOutput.h"
#include "fileInput.h"
#include "PCB.h"
#include <cmath>
#include <ctime>
#include <random>
#include <cstdlib>
using namespace std;



int main() {
	srand(time(NULL));
	vector<PCB> processes;
	writeToFile();
	processes = readFile(processes);
}
