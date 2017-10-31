#pragma once

using c_uShort = const unsigned short;
using uShort = unsigned short;

// Klasa disk_drive reprezentuje fizyczny dysk twardy
// Dysk widoczny jest jako pamięć ciągła
// Dysk może odczytać dowolny sektor
// Dysk może zapisać dowolny sektor
// Volume Contol Block zawiera informacje potrzebne do odczytu istniejących sektorów oraz alokacji nowych

class disk_drive final
{
public:
	disk_drive();
	~disk_drive();

	void readSector(c_uShort sectorNumber, char sector[]);
	void writeSector(c_uShort sectorNumber, char sector[]);
	void clear();

	//Volume Control Block
	c_uShort diskSize;
	c_uShort sectorSize;
	c_uShort numberOfSectors;

	void printDisk(bool asChar = 1);
private:
	char* diskSpace; 
};

