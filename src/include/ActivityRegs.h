#pragma once

#include <stack>
#include "SymbolTable.h"

class ActivityRegs {
	protected:
		std::stack<SymbolTable*> mTables;
	public:
		void push(SymbolTable* table);
		void pop();
		SymbolTable* top();
};

