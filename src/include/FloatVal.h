#pragma once

#include "ExprVal.h"

class FloatVal: public ExprVal<float> {
	public:
		FloatVal(float value);
};

