#pragma once

#include "ExprVal.h"

class BoolVal: public ExprVal<bool> {
	public:
		BoolVal(bool value);
};
