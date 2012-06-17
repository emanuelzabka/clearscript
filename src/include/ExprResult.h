#pragma once

#include <string>
#include "ExprVal.h"

class ExprResult {
	protected:
		std::string mType;
		Val* mValue;

	public:
		ExprResult(std::string type, Val* value);
		std::string getType();
		Val* getValue();
};

