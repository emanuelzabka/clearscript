#pragma once

#include "ExprVal.h"

class LongVal: public ExprVal<long> {
	public:
		LongVal(long value);
};

