#include <iostream>
#include <string>
#include <list>
#include "../Headers/ProcessesManager.h"

//Tworzenie w konstruktorze pierwszej listy dla wszystkich procesów ,listy 
ProcessesManager::ProcessesManager()
{
	std::list<Process*>list;
	allProcesses.push_back(list); // GroupID == 0
}

//Tworzenie procesu. Jeszcze brak grupowania procesów
void ProcessesManager::createProcess(std::string fileName, int GID)
{
	Process* newProcess = new Process(fileName, GID);


	
	std::list<std::list<Process*>>::iterator it = allProcesses.begin();
	(*it).push_back(newProcess);

	waitingProcesses.push_front(newProcess);

}
void ProcessesManager::killProcess(int PID)
{

	for (std::list<std::list<Process*>>::iterator it = allProcesses.begin(); it != allProcesses.end(); it++)
	{
		for (std::list<Process*>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++)
		{
			if ((*it2)->GetPID == PID)
			{
				delete (*it2);
			}
		}
	}
}