#pragma once

#include <string>
#include <vector>
#include "ExprVal.h"
#include "Val.h"

class VectorVal: public ExprVal< std::vector<Val*> > {
	public:
		VectorVal(std::vector<Val*> value);
};

