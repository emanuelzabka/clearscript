#pragma once

#include "ExprVal.h"

class IntVal: public ExprVal<int> {
	public:
		IntVal(int value);
};

