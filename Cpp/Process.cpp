#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>
#include "../Headers/Process.h"

int Process::processesCounter = 0;

Process::Process(std::string fileName, int GID)
{
	this->PID = processesCounter++;
	this->GID = GID;
	this->state = State::New;
	this->instructionCounter = 0;
	this->registers.R1 = 0;
	this->registers.R2 = 0;
	this->burstTime = 10;
	this->fileName = fileName;
	this->state = State::Waiting;
}

void Process::SetState(State newState) 
{
	this->state = newState;
}
void Process::SetProcesBurstTime(int newBurstTime)
{
	this->burstTime = newBurstTime;
}
int Process::GetProcesBurstTime()
{
	return burstTime;
}
int Process::GetPID()
{
	return PID;
}

int Process::GetGID()
{
	return GID;
}
std::string Process::GetFileName()
{
	return fileName;
}
State Process::GetState()
{
	return state;
}
std::vector<std::pair<int, bool>> Process::GetPages() 
{
	return pages;
};
void Process::SetPages(std::vector<std::pair<int, bool>> newPages) 
{
	this->pages = newPages;
};
int Process::GetPageCount() 
{
	return pageCount;
};
void Process::SetPageCount(int newPageCount) 
{
	this->pageCount = newPageCount;
};
void Process::displayProcess()
{
	std::cout << "PID: " << GetPID() << ", GID: " << GetGID() << ", File name: " << GetFileName() << ", Burst time: " << GetProcesBurstTime() << ", State: " << GetState() << std::endl;
}