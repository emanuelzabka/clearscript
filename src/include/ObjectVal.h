#pragma once

#include "ExprVal.h"
#include "Object.h"

class ObjectVal: public ExprVal<Object*> {
	public:
		ObjectVal(Object* value);
};

