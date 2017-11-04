#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>
#include "../Headers/Process.h"

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