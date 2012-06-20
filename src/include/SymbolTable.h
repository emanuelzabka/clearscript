#pragma once

#include <map>
#include "Symbol.h"

class SymbolTable {
	protected:
		SymbolTable* mParent;
		std::map<std::string, Symbol*> mSymbols;
	public:
		SymbolTable();
		~SymbolTable();
		SymbolTable(SymbolTable* parent);

		void add(Symbol* symbol);
		Symbol* get(std::string name);
};

