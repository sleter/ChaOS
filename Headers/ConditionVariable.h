#include "Process.h"
#include <list>

class ConditionVariable
{
private:
	static bool processTerminated;
	std::list<Process*> waitingProcesses;

public:
	ConditionVariable();
	void wait(Process* process);
	void signal();
	void freeProcessor();
	void busyProcessor();
	void displayWaitingProcesses();
	bool getProcessTerminated();
};