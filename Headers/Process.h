#pragma once
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>

enum State { New, Ready, Waiting, Running, Terminated };

struct Registers {
	int R1;
	int R2;
};

class Process
{
private:
	int PID;
	int GID;
	State state;
	int instructionCounter;
	Registers registers;
	int burstTime;
	std::string fileName;
	std::vector<std::pair<size_t, bool>> allocatedPages;
	size_t numberOfPages;


public:
	static int processesCounter;
	Process(std::string fileName, int GID) {};
	void SetState(State newState) {};
	void SetProcesBurstTime(int newBurstTime) {};
	int GetProcesBurstTime() {};
	int GetPID() {};
};

int Process::processesCounter = 0;