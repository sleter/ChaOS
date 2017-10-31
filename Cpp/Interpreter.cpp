#include <iostream>
#include <string>
#include <vector>
#include "Interpreter.h"
#include <algorithm>


//Wykonywanie rozkazu
void Interpreter::DoCommand(std::string& command_code)
{
	//Wczytywanie ID rozkazu, oraz ilo�ci argument�w
	std::pair<int, int > CommandParameters = GetParameters(command_code);
	std::vector<std::string>Arguments;

	//Wczytywanie Argument�w
	for (int i = 0; i < CommandParameters.second; i++) {
		Arguments.push_back(getArgument());//od osoby zarz�dzaj�cej pami�ci�
	}

	//Testowo - wy�wietlenie wczytanego rozkazu i jego argument�w;
	std::cout << "ID: " << CommandParameters.first << " | Command name: " << command_code;
	for (int i = 0; i < Arguments.size(); i++) {
		std::cout << " | Arg[" << i << "]: " << Arguments[i] << " ";
	}
	std::cin.ignore(2);

	RegStatus();

	//Wyb�r rozkazu
	int arg1, arg2;
	switch (CommandParameters.first)
	{
	case 0://AD = Dodawanie
		std::clog << "Wykonuje si� operacja dodawania..." << std::endl;
		arg1 = atoi(Arguments[0].c_str());
		arg2 = atoi(Arguments[1].c_str());
		REG[arg1] += REG[arg2];
		RegStatus();
		break;
	case 1://SB = Odejmowanie
		std::clog << "Wykonuje si� operacja odejmowania..." << std::endl;
		arg1 = atoi(Arguments[0].c_str());
		arg2 = atoi(Arguments[1].c_str());
		REG[arg1] -= REG[arg2];
		RegStatus();
		break;
	case 2://ML = MNO�ENIE
		std::clog << "Wykonuje si� operacja mno�enia..." << std::endl;
		arg1 = atoi(Arguments[0].c_str());
		arg2 = atoi(Arguments[1].c_str());
		REG[arg1] *= REG[arg2];
		RegStatus();
		break;
	case 3://DV = DZIELENIE
		std::clog << "Wykonuje si� operacja dzielenia..." << std::endl;
		arg1 = atoi(Arguments[0].c_str());
		arg2 = atoi(Arguments[1].c_str());
		REG[arg1] /= REG[arg2];
		RegStatus();
		break;
	case 4://DR = DEKREMENTACJA
		std::clog << "Wykonuje si� operacja dekrementacji..." << std::endl;
		arg1 = atoi(Arguments[0].c_str());
		REG[arg1]--;
		RegStatus();
		break;
	case 5://IR = INKREMENTACJA
		std::clog << "Wykonuje si� operacja inkrementacji..." << std::endl;
		arg1 = atoi(Arguments[0].c_str());
		REG[arg1]++;
		RegStatus();
		break;
	case 6://MV =PRZENOSZENIE WARTO�CI
		std::clog << "Wykonuje si� operacja przypisania warto�ci..." << std::endl;
		arg1 = atoi(Arguments[0].c_str());
		arg2 = atoi(Arguments[1].c_str());
		REG[arg1] = arg2;
		RegStatus();
		break;

		//OPERACJE NA PLIKACH
	case 7://MF = Utw�rz plik
		break;
	case 8://SF = Zapis do pliku
		break;
	case 9://DF = Usuwanie pliku
		break;
	case 10://RF = Odczyt pliku
		break;
	case 11://LS = Listuj pliki
		break;
	case 12://CP = Zmie� nazw� pliku
		break;

		//PROCESY
	case 13://MP = Utw�rz proces
		break;
	case 14://EX = Wykonaj program?
		break;
	case 15://PS = Wy�wietl procesy
		break;
	case 16://SM = Wy�lij komunikat
		break;
	case 17://RM = Odczytaj komunikat
		break;
	case 18://ET = Utw�rz etykiet�
		break;
	case 19://JP = Skok bezwarunkowy
		break;
	case 20://JZ = Skok je�li flaga zerowa jest ustawiona
		break;
	case 21://CM = Skok przyr�wnanie
		break;
	case 22://RT = Zwr��
		break;
	case 23://SP = Koniec programu
		break;
	default:
		std::cout << "ERROR - NIE OBS�UGIWANE POLECENIE!" << std::endl;
		std::cin.ignore(1);

		break;
	}


}


//Pobiera ID oraz ilo�� parametr�w z tablicy rozkaz�w
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
	std::clog << "Wprowad� argument:";
	std::cin >> arg;
	std::clog << std::endl;
	return arg;
}

//Wy�wietla aktualny stan rejestr�w
void Interpreter::RegStatus()
{
	std::cout << "Aktualny stan rejestr�w" << std::endl;
	std::cout << "R0: " << REG[0] << " | R1: " << REG[1] << " | R2 " << REG[2] << std::endl;
	std::cin.ignore(1);
}
