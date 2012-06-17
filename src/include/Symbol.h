#pragma once

#include <string>
#include "Val.h"

class Symbol {
	protected:
		std::string mName;
		std::string mType;
		Val* mValue;
	public:
		Symbol(std::string name, std::string type);
		std::string getName();
		std::string getType();
		void setType(std::string type);
		Val* getValue();
		void setValue(Val* value);
};

