// Shell_.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <Windows.h>
#include <string>
#include <fstream>
//#include <map>
#include <vector>

using namespace std;

class main_loop {
private:
	string line, command, path;
	void choose_function();
	void initialize();
	void prepare_string();
	void help();
	

public:
	main_loop();
	void run();
};



void main_loop::initialize() {
	//uruchmienie logo

	cout << "________/\\\\\\\\\\\\\\\\\\__/\\\\\\______________________________/\\\\\\\\\__________/\\\\\\\\\\\\\\\\\\\\\\___        " << endl
		 << " _____/\\\\\\////////__\\/\\\\\\____________________________/\\\\\\///\\\\\\______/\\\\\\/////////\\\\\\_       " << endl
		 << "  ___/\\\\\\/___________\\/\\\\\\__________________________/\\\\\\/__\\///\\\\\\___\\//\\\\\\______\\///__      " << endl
		 << "   __/\\\\\\_____________\\/\\\\\\__________/\\\\\\\\\\\\\\\\\\_____/\\\\\\______\\//\\\\\\___\\////\\\\\\_________     " << endl
		 << "    _\\/\\\\\\_____________\\/\\\\\\\\\\\\\\\\\\\\__\\////////\\\\\\___\\/\\\\\\_______\\/\\\\\\______\\////\\\\\\______    " << endl
		 << "     _\\//\\\\\\____________\\/\\\\\\/////\\\\\\___/\\\\\\\\\\\\\\\\\\\\__\\//\\\\\\______/\\\\\\__________\\////\\\\\\___   "<<endl
		 << "      __\\///\\\\\\__________\\/\\\\\\___\\/\\\\\\__/\\\\\\/___\\\\\\___\\///\\\\\\__/\\\\\\_____/\\\\\\______\\//\\\\\\__  "<<endl
		 << "       ____\\////\\\\\\\\\\\\\\\\\\_\\/\\\\\\___\\/\\\\\\_\\//\\\\__\\\\\\/\\\\____\\///\\\\\\\\\\/_____\\///\\\\\\\\\\\\\\\\\\\\\\/___ "<<endl
		 << "        _______\\/////////__\\///____\\///___\\////////\\//_______\\/////_________\\///////////_____" << endl;

	//uruchamiam tutaj moduły innych osób
}


void main_loop::prepare_string() {
	command = line;
}

void main_loop::run() {
	initialize();
	while (true) {
		try {
		cout << "> ";
		getline(cin, line);
		
			if (line == "close")break;
			else {
				prepare_string();
				choose_function();
			}
		}
		catch (...) {
			cout << "Bledna nazwa rozkazu. \nWpisz \"help\" zeby zobaczyc liste rozkazow\n";
		}
	}
}

main_loop::main_loop() {
	command = "";
	line = "";
	path = "";
}

void main_loop::choose_function() {
	if (command == "help") {
		//help();
	}
	else if (command == "xD") {
		cout << "           /$$$$$$$ " << endl
			<< "          | $$__  $$" << endl
			<< " /$$   /$$| $$  \\ $$" << endl
			<< "|  $$ /$$/| $$  | $$" << endl
			<< " \\  $$$$/ | $$  | $$" << endl
			<< "  >$$  $$ | $$  | $$" << endl
			<< " /$$/\\  $$| $$$$$$$/" << endl
			<< "|__/  \\__/|_______/ " << endl;

	}
	else if (command == "ayy") {
		cout << "_    _  _ ____ ____ " << endl
			<< "|    |\\/| |__| |  | " << endl
			<< "|___ |  | |  | |__| " << endl;

	}
	else {
		throw 1;
	}


}


int main() {
	main_loop m;
	m.run();
	return EXIT_SUCCESS;
}




