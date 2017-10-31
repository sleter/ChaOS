#pragma once
#include <iostream>
#include <list>

class ProcessScheduler { //class responsible for all the planning
public:
	//Structures declarations:
	struct Process { //structure representing the most basic concept of a process
	public:
		int ID, arrivalTime, burstTime; //ID stores an identificator of a process; arrivalTime stores the time when process has arrived in the system; burstTime stores a possible time of execution
	public:
		Process(int ID, int arrivalTime, int burstTime); //constructor with 3 parameters
	};

public:
	//Variables declarations:
	std::list<Process> listProcess; //listProcess std::list - ready-queue-like

public:
	// Methods declarations:
	void GetProcesses(); //method responsible for pushing processes into ready-queue
	void SRTSchedulingAlgorithm(); //implementation of the Shortest Remaining Time First Algorithm for scheduling processes
};
