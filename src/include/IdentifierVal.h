#pragma once

#include "ExprVal.h"
#include "Symbol.h"

class IdentifierVal: public ExprVal<Symbol*> {
	public:
		IdentifierVal(Symbol* value);
		Symbol* getValue();
};

