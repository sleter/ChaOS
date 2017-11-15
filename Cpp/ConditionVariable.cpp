#include "ConditionVariable.h"
#include "ProcessScheduling.h"
#include "Process.h"
#include <iostream>

ConditionVariable::ConditionVariable()
{
	processTerminated = true;
}

//Changes process state to waiting and adds it to waiting list. Activates scheduler.
void ConditionVariable::wait(Process* process)
{
	process->SetState(State::Waiting);
	waitingProcesses.push_back(process);
	//SRTSchedulingAlgorithm();
}

//Changes process state, deletes it from waitingProcesses list. Activates scheduler.
void ConditionVariable::signal()
{
	if (processTerminated)
	{
		waitingProcesses.front->SetState(State::Ready);
		//To implement: Adding process in "ready" state to ProcessScheduling std::list<Process> processList;
		waitingProcesses.pop_front();
		//SRTSchedulingAlgorithm();
	}
}

//For scheduler and other modules - sets processTerminated variable to true which means that the other process can
//start its calculations.
void ConditionVariable::freeProcessor()
{
	if (!processTerminated)
	{
		processTerminated = true;
	}
}

//For scheduler and other modules - changes the variable processTerminated to false wchich means that the other process
//cannot get access to processor.
void ConditionVariable::busyProcessor()
{
	if (processTerminated)
	{
		processTerminated = false;
	}
}

//Just to show waitingProcesses list.
void ConditionVariable::displayWaitingProcesses()
{
	for (std::list<Process*>::iterator it = waitingProcesses.begin(); it != waitingProcesses.end(); it++)
	{
		//Waiting for method to display process parameters.
	}
}


bool ConditionVariable::getProcessTerminated()
{
	return processTerminated;
}