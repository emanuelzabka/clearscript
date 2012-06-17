#pragma once

#include <string>
#include "ExprVal.h"

class ExprResult {
	protected:
		std::string mType;
		Val* mValue;

	public:
		std::string getType();
		Val* getValue();
};

