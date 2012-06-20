#include <string>
#include <cstdlib>
#include <iostream>
#include "Log.h"

Log* Log::mInstance = NULL;

Log* Log::getInstance()
{
	if (!mInstance)
	{
		mInstance = new Log();
	}
	return mInstance;
}

void Log::fatal(std::string msg)
{
	std::cout << msg << "\n";
	exit(1);
}
