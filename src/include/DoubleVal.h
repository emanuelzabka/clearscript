#pragma once

#include "ExprVal.h"

class DoubleVal: public ExprVal<double> {
	public:
		DoubleVal(double value);
};

