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
	std::vector<std::pair<int, bool>> pages;
	int pageCount;


public:
	static int processesCounter;
	Process(std::string fileName, int GID);
	void SetState(State newState);
	void SetProcesBurstTime(int newBurstTime);
	int GetProcesBurstTime();
	int GetPID();
	int GetGID();
	std::string GetFileName();
	State GetState();
	std::vector<std::pair<int, bool>> GetPages();
	void SetPages(std::vector<std::pair<int, bool>> newPages);
	int GetPageCount();
	void SetPageCount(int newPageCount);
	void displayProcess();
};