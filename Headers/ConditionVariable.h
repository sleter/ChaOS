#include "Process.h"
#include <list>

class ConditionVariable
{
private:
	static bool schedulerState;
	std::list<Process*> waitingProcesses;

public:
	ConditionVariable();
	void wait(Process* process);
	void signal();
	void freeScheduler();
	void busyScheduler();
	void displayWaitingProcesses();
};