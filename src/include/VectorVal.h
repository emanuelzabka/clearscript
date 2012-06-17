#pragma once

#include <string>
#include <vector>
#include "ExprVal.h"

class VectorVal: public ExprVal<std::vector<std::string>*> {
	public:
		VectorVal(std::vector<std::string>* value);
};

