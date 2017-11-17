#include "ProcessScheduling.h"

void ProcessScheduler::GetReadyProcessesList() {
	readyProcesses = pm.GiveReadyProcessesList();
}

//void SetProcesBurstTime(int newBurstTime);
//int GetProcesBurstTime();


void ProcessScheduler::SRTSchedulingAlgorithm() {
	std::list<Process*>::iterator iteratorToMinElement;
	int currentProcessActualBurstTime = 0;
	int minBurstTime = 100;
	while (readyProcesses.size() > 1) { // > 1 poniewa� zawsze b�dzie wewn�trz proces bezczynno�ci
		for (std::list<Process*>::iterator it = readyProcesses.begin(); it != readyProcesses.end(); it++) {
			if ((*it)->GetProcesBurstTime() <= minBurstTime) {
				minBurstTime = (*it)->GetProcesBurstTime();
				iteratorToMinElement = it;
			}
		}

		//Wywo�anie funkcji GoProcess(iteratorToMinElement) z wywo�aniami wszystkich wa�nych funkcji
		//Zmienianie warto�ci currentProcessActualBurstTime potrzebnej do obliczenia burst time po wykonaniu instrukcji
		
		
		// this part should run when some instruction on process has been done in order to count new burstTime for process
		(*iteratorToMinElement)->SetProcesBurstTime(.5 * currentProcessActualBurstTime + .5 * (*iteratorToMinElement)->GetProcesBurstTime); //ustawianie nowego czasu burstTime procesu
		
		//sprawdzanie czy proces jest skonczony; je�li tak - zmieni� mu stan lub po prostu go usun��.
	}
}