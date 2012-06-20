#pragma once

#include <vector>
#include <string>
#include "SymbolTable.h"

class ActivationReg {
	protected:
		std::vector<SymbolTable*> mTables;
		static ActivationReg* mInstance;
		ActivationReg();
	public:
		static ActivationReg* getInstance();
		void push(SymbolTable* table);
		void pop();
		SymbolTable* top();
		SymbolTable* global();
		Symbol* getUserType(std::string type);
		bool isBuiltinType(std::string type);
};

