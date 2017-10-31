#pragma once
#include <iostream>
#include <string>
#include <vector>


class Interpreter
{
	//Rejestry
	int REG[3]{ 0,0,0 };



	//tablica rozkaz�w <KOD ROZKAZU <ID rozkazu/ilo�� argument�w>>
	std::vector<std::pair<std::string, std::pair<int, int >>> CommandTab{

		//Arytmetyka
		std::make_pair("AD",std::make_pair(0,2)),//DODAWANIE 
		std::make_pair("SB",std::make_pair(1,2)),//ODEJMOWANIE
		std::make_pair("ML",std::make_pair(2,2)), //MNO�ENIE
		std::make_pair("DV",std::make_pair(3,2)), //DZIELENIE
		std::make_pair("DR",std::make_pair(4,1)), //DEKREMENTACJA
		std::make_pair("IR",std::make_pair(5,1)), //INKREMENTACJA
		std::make_pair("MV",std::make_pair(6,2)), //PRZENOSZENIE WARTO�CI

		//Operacje na plikach
		std::make_pair("MF",std::make_pair(7,1)), //Utw�rz plik
		std::make_pair("SF",std::make_pair(8,2)), //Zapis do pliku
		std::make_pair("DF",std::make_pair(9,1)), //Usuwanie pliku
		std::make_pair("RF",std::make_pair(10,1)), //Odczyt pliku
		std::make_pair("LS",std::make_pair(11,0)), //Listuj pliki
		std::make_pair("CP",std::make_pair(12,2)), //Zmie� nazw� pliku

		//Procesy
		std::make_pair("MP",std::make_pair(13,0)), //Utw�rz proces
		std::make_pair("EX",std::make_pair(14,1)), //Wykonaj program?
		std::make_pair("PS",std::make_pair(15,0)), //Wy�wietl procesy
		std::make_pair("SM",std::make_pair(16,2)), //Wy�lij komunikat
		std::make_pair("RM",std::make_pair(17,1)), //Odczytaj komunikat

		//Programowe
		std::make_pair("ET",std::make_pair(18,0)), //Utw�rz etykiet�
		std::make_pair("JP",std::make_pair(19,1)), //Skok bezwarunkowy
		std::make_pair("JZ",std::make_pair(20,1)), //Skok je�li flaga zerowa jest ustawiona
		std::make_pair("CM",std::make_pair(21,2)), //Skok przyr�wnanie
		std::make_pair("RT",std::make_pair(22,1)), //Zwr��
		std::make_pair("SP",std::make_pair(23,1)), //Koniec programu



		std::make_pair("ER",std::make_pair(99,0)) //Error - nie obs�ugiwane polecenie

	};

	//wykonaj rozkaz

	std::pair<int, int > GetParameters(std::string& cmd);

	//Tymczasowe wpisywanie argument�wl
	std::string getArgument();

	//Stan rejestr�w
	void RegStatus();

public:
	Interpreter() {};

	//Wykonaj rozkaz (kod rozkazu)
	void DoCommand(std::string& command_code);
};
