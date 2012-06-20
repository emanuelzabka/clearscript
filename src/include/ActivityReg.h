#pragma once

#include <vector>
#include <string>
#include "SymbolTable.h"

class ActivityReg {
	protected:
		std::vector<SymbolTable*> mTables;
		static ActivityReg* mInstance;
		ActivityReg();
	public:
		static ActivityReg* getInstance();
		void push(SymbolTable* table);
		void pop();
		SymbolTable* top();
		Symbol* getUserType(std::string type);
		bool isBuiltinType(std::string type);
};

