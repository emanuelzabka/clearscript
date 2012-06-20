#include "SymbolTable.h"

SymbolTable::SymbolTable()
{
	mParent = NULL;
}

SymbolTable::~SymbolTable()
{
	for (int i = 0; i < mSymbols.size(); i++)
	{
		delete mSymbols[i];
	}
}

SymbolTable::SymbolTable(SymbolTable* parent)
{
	mParent = parent;
}

void SymbolTable::add(Symbol* symbol)
{
	mSymbols[symbol->getName()] = symbol;
}

Symbol* SymbolTable::get(std::string name)
{
	if (mSymbols.count(name) > 0)
		return mSymbols[name];
	else
		return NULL;
}
