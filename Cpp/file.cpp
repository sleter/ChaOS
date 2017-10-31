#include "file.h"



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
	fileSize = text.size();
}

std::string file::read()
{
	return fileContent;
}