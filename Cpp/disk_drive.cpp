#include "disk_drive.h"
#include "iostream"

disk_drive::disk_drive()
	: diskSize(1024), sectorSize(32), numberOfSectors(diskSize / sectorSize)
{
	diskSpace = new char[diskSize];
	clear();
}

disk_drive::~disk_drive()
{
	delete[diskSize] diskSpace;
}

void disk_drive::readSector(c_uShort sectorNumber, char sector[])
{
	for (int i = sectorNumber*sectorSize, j=0; i < (sectorSize*sectorNumber + sectorSize); i++, j++)
	{
		sector[j] = diskSpace[i];
	}
}

void disk_drive::writeSector(c_uShort sectorNumber, char sector[])
{
	for (int i = sectorNumber*sectorSize, j=0; i < (sectorSize*sectorNumber+sectorSize); i++, j++)
	{
		diskSpace[i] = sector[j];
	}
}

void disk_drive::clear()
{
	for (int i = 0; i < diskSize; i++)
	{
		diskSpace[i] = 0x0;
	}
}

void disk_drive::printDisk(bool asChar)
{
	if(asChar)
	for (int i = 0; i < diskSize; i++)
	{
		std::cout << ((uShort(~0) >> 8) & (diskSpace[i])) << " ";
		if ((i + 1) % 32 == 0) std::cout << std::endl;
	}
	else
		for (int i = 0; i < diskSize; i++)
		{
			std::cout << diskSpace[i] << " ";
			if ((i + 1) % 32 == 0) std::cout << std::endl;
		}
	std::cout << std::flush;
}
