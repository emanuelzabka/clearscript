#pragma once

#include <vector>
#include <string>
#include "SymbolTable.h"

class ActivityRegs {
	protected:
		std::vector<SymbolTable*> mTables;
		static ActivityRegs* mInstance;
		ActivityRegs();
	public:
		static ActivityRegs* getInstance();
		void push(SymbolTable* table);
		void pop();
		SymbolTable* top();
		Symbol* getUserType(std::string type);
		bool isBuiltinType(std::string type);
};

