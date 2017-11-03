#include "ProcessScheduling.h"

ProcessScheduler::Process::Process(int ID, int arrivalTime, int burstTime) { //implementation of the Process's constructor
	this->ID = ID;
	this->arrivalTime = arrivalTime;
	this->burstTime = burstTime;
}

void ProcessScheduler::GetProcesses() { //implementation of the GetProcesses method; due to the fact that not all the modules have been implemented yet values are being set here manually
	listProcess.push_back(Process(1, 0, 7));
	listProcess.push_back(Process(2, 1, 5));
	listProcess.push_back(Process(3, 2, 3));
	listProcess.push_back(Process(4, 3, 1));
	listProcess.push_back(Process(5, 4, 2));
	listProcess.push_back(Process(6, 5, 1));
}

void ProcessScheduler::SRTSchedulingAlgorithm() {
	int timePassed = 0; //timePassed responsible for simmulating the process of time passing
	int minBurstTime = 100; //minBurstTime stores minimal burst time of a process iteratorToMinElement; used for comparison with other burstTimes to find the minimal one
	std::list<Process>::iterator iteratorToMinElement; //candidate process to be executed next
	while (listProcess.size() > 0) { //while-loop looping as long as processes are availible inside ready-queue (in this example linked list)
		std::cout << "Time passed:\t\t" << timePassed << "\n";
		for (std::list<Process>::iterator it = listProcess.begin(); it != listProcess.end(); it++) { //for-loop based on std::list<Process>::iterators looping over all processes in ready-queue
			if (it->arrivalTime <= timePassed && it->burstTime <= minBurstTime) { //if-statement which finds the next candidate process to be executed next
				minBurstTime = it->burstTime; //storing the minimal burstTime (found so far) inside ready-queue 
				iteratorToMinElement = it; //storing the iterator to the best candidate process (found so far)
			}
		}

		std::cout << "Process being executed:\t\t" << iteratorToMinElement->ID << "\n";
		iteratorToMinElement->burstTime--; //decreasing the burstTime value, since one unit of time has passed
		timePassed++;
		if (!iteratorToMinElement->burstTime) { //if-statement checking whether a current process being executed has already ended processing itself
			std::cout << "Process: \t" << iteratorToMinElement->ID << "\tterminated at time:\t" << timePassed << "s" << std::endl;
			listProcess.erase(iteratorToMinElement); //erasing the terminated process
			minBurstTime = 100; //setting minBurstTime to simmingly high value, since we don't know how high is the next minimal value for next process to be executed 
		}
	}
}

//	ProcessScheduler ps;
//	ps.GetProcesses();
//	ps.SRTSchedulingAlgorithm();