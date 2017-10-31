#include <iostream>
#include <string>
#include <vector>
#include "InrerpreterL.h"
#include <algorithm>


//Wykonywanie rozkazu
void Interpreter::DoCommand(std::string& command_code)
{
	//Wczytywanie ID rozkazu, oraz iloœci argumentów
	std::pair<int, int > CommandParameters = GetParameters(command_code);
	std::vector<std::string>Arguments;

	//Wczytywanie Argumentów
	for (int i = 0; i < CommandParameters.second; i++) {
		Arguments.push_back(getArgument());//od osoby zarz¹dzaj¹cej pamiêci¹
	}

	//Testowo - wyœwietlenie wczytanego rozkazu i jego argumentów;
	std::cout << "ID: " << CommandParameters.first << " | Command name: " << command_code;
	for (int i = 0; i < Arguments.size(); i++) {
		std::cout << " | Arg[" << i << "]: " << Arguments[i] << " ";
	}
	std::cin.ignore(2);

	//Wybór rozkazu
	switch (CommandParameters.first)
	{
	case 0://AD = Dodawanie
		break;
	case 1://SB = Odejmowanie
		break;
	case 2://ML = MNO¯ENIE
		break;
	case 3://DV = DZIELENIE
		break;
	case 4://DR = DEKREMENTACJA
		break;
	case 5://IR = INKREMENTACJA
		break;
	case 6://MV =PRZENOSZENIE WARTOŒCI
		break;
	case 7://MF = Utwórz plik
		break;
	case 8://SF = Zapis do pliku
		break;
	case 9://DF = Usuwanie pliku
		break;
	case 10://RF = Odczyt pliku
		break;
	case 11://LS = Listuj pliki
		break;
	case 12://CP = Zmieñ nazwê pliku
		break;
	case 13://MP = Utwórz proces
		break;
	case 14://EX = Wykonaj program?
		break;
	case 15://PS = Wyœwietl procesy
		break;
	case 16://SM = Wyœlij komunikat
		break;
	case 17://RM = Odczytaj komunikat
		break;
	case 18://ET = Utwórz etykietê
		break;
	case 19://JP = Skok bezwarunkowy
		break;
	case 20://JZ = Skok jeœli flaga zerowa jest ustawiona
		break;
	case 21://CM = Skok przyrównanie
		break;
	case 22://RT = Zwróæ
		break;
	case 23://SP = Koniec programu
		break;
	default:
		std::cout << "ERROR - NIE OBS£UGIWANE POLECENIE!" << std::endl;
		std::cin.ignore(1);

		break;
	}

}


//Pobiera ID oraz iloœæ parametrów z tablicy rozkazów
std::pair<int, int > Interpreter::GetParameters(std::string& cmd)
{
	std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::toupper);
	for (int i = 0; i < CommandTab.size(); i++) {
		if (CommandTab[i].first == cmd) {
			return CommandTab[i].second;
		}
	}
	cmd = "ER";
	return CommandTab[CommandTab.size() - 1].second;
}



//Symulacja podawania argumentu
std::string Interpreter::getArgument()
{
	std::string arg;
	std::clog << "WprowadŸ argument:";
	std::cin >> arg;
	std::clog << std::endl;
	return arg;
}

