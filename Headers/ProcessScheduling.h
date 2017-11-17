#pragma once
#include <iostream>
#include <list>
#include "ProcessesManager.h"

class ProcessScheduler {
private:
	std::list<Process*> readyProcesses;
	void GetReadyProcessesList();
	//jedynie na potrzeby implementacji (bo bêdzie chyba utworzone w mainie?):
	ProcessesManager pm;
public:
	void SRTSchedulingAlgorithm(); //implementation of the Shortest Remaining Time First Algorithm for scheduling processes
};