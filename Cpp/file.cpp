﻿#include "../Headers/file.h"
#include "../Headers/ChaOS_filesystem_exception.h"


file::file()
{
}

file::~file()
{
}


void file::write(const std::string & text)
{
	fileSize = text.size();
	fileContent = text;

	if (fileSize > 255) 
	{
		fileSize = 255;
		fileContent.erase(fileContent.begin() + 255, fileContent.end());
		throw fileToLong();
	}
}

std::string file::read()
{
	return fileContent;
}