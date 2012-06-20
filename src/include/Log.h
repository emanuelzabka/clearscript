#pragma once

#include <string>

class Log {
	protected:
		static Log* mInstance;
		~Log(){};
	public:
		static Log* getInstance();
		static void fatal(std::string msg);
};

