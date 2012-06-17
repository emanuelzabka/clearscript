#pragma once

#include <string>
#include "ExprVal.h"

class StringVal: public ExprVal<std::string> {
	public:
		StringVal(std::string value);
};

