#include "ConditionVariable.h"
#include "ProcessScheduling.h"
#include "Process.h"
#include <iostream>

ConditionVariable::ConditionVariable()
{
	schedulerState = true;
}

//Changes process state to waiting and adds it to waiting list. Activates scheduler.
void ConditionVariable::wait(Process* process)
{
	process->SetState(State::Waiting);
	waitingProcesses.push_back(process);
	SRTSchedulingAlgorithm();
}

//Changes process state, deletes it from waitingProcesses list. Activates scheduler.
void ConditionVariable::signal()
{
	if (schedulerState)
	{
		waitingProcesses.front->SetState(State::Ready);
		//To implement: Adding process in "ready" state to ProcessScheduling std::list<Process> processList;
		waitingProcesses.pop_front();
		SRTSchedulingAlgorithm();
	}
}

//For scheduler. Changes the state of scheduler to free (new processes can be added to its "ready processes list".
void ConditionVariable::freeScheduler()
{
	if (!schedulerState)
	{
		schedulerState = true;
	}
}

//For scheduler. Changes the state of scheduler to busy (new processes cannot be added to its "ready processes list".
void ConditionVariable::busyScheduler()
{
	if (schedulerState)
	{
		schedulerState = false;
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