#pragma once

#include "disk_drive.h"
#include "file.h"
#include "stack"
#include "exception"
#include "sstream"

class outOfMemory : public std::exception 
{
public:
	outOfMemory();
};

class objectNotFound : public std::exception
{
public:
	objectNotFound();
};

class objectExists : public std::exception
{
public:
	objectExists();
};



struct bitMask 
{
	bool getBit(unsigned int INT, unsigned int i);
	unsigned int setBit(unsigned int INT, unsigned int i, bool value);
};

class ChaOS_filesystem final
{
public:

	enum class type
	{
		file = 'F', dir = 'D'
	};

	ChaOS_filesystem();
	~ChaOS_filesystem();

	// tworzy obiekt w aktualnym folderze
		void create(const char* name, type t); //(v)

	// usuwa obiekt z aktualnego folderu
		void remove(const char* name); //(v)
	
	// Zwraca string opisujący zawartość aktualnego folderu
		std::string listDirectory(); //(v)

	// zmiania aktualny folder na wskazany folder
		void changeDirectory(const char* name); //(v)

	// zmiania aktualny folder na wskazany folder
		void backDirectory(); //(v)

	// zmiania aktualny folder na wskazany folder
		void rootDirectory(); //(v)

	// zmienia nazwę obiektu w aktualnym folderze
		void rename(const char* name, const char* newname); //(v)
	
	// szuka pliku/katalogu w aktualnym katalogu. Zwraca adres pierwszego sektora szukanego pliku/katalogu lub 0, gdy nie istnieje
		uShort search(const char* name, type t); //(v)

	// otwiera plik o wskazanej nazwie
		void openFile(const char* filename); // (v) przetestować

	//zapisuje aktualny plik
		void saveFile();

	// zwalnia uchwyt currentFile
		void closeFile(); //(v)

	// do kontroli 
		std::string printSector(const unsigned short number);
		std::string printDiskStats();

	file* currentFile;

	disk_drive& getDisk();

private:
	uShort currentFileFirst;
	uShort currentFileSector;
	uShort currentDirFirst;
	uShort currentDirSector;

	disk_drive disk;
	uShort rootDirSector;

	std::stack<uShort> returnPath;

	void addRow(char* sector, char* row);
	void getRow(char* sector, char* row);
	bool equalName(const char* n1,const char* n2);
	uShort charArrSize(const char* arr);
	void toChar5(const char* arr,char* result5);

	c_uShort allocateSector();
	void freeSector(uShort number);
};

