#pragma once

#include "../Headers/disk_drive.h"
#include "../Headers/file.h"
#include "../Headers/ChaOS_filesystem_exception.h"
#include "stack"
#include "sstream"


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
		void openFile(const char* filename); // (v)

	//zapisuje aktualny plik
		void saveFile();  // (v)

	// zwalnia uchwyt currentFile
		void closeFile(); //(v)

	// do kontroli 
		std::string printSector(const unsigned short number);
		std::string printSectorsChain(const unsigned short first);
		std::string printDiskStats();

	file* currentFile;

	disk_drive& getDisk();

private:

	c_uShort allocateSector();
	void freeSector(uShort number);

	// Przechowują "wskaźniki" na plik/katalog
	uShort currentFileFirst;
	uShort currentFileSector;
	uShort currentDirFirst;
	uShort currentDirSector;
	uShort rootDirSector;

	disk_drive disk;

	std::stack<uShort> returnPath;

	void addRow(char* sector, char* row);
	void getRow(char* sector, char* row);
	bool equalName(const char* n1,const char* n2);
	uShort charArrSize(const char* arr);
	void toChar5(const char* arr,char* result5);
	std::string asBitVector(const int vector);
};

