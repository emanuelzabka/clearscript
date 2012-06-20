#include "SymbolTable.h"

SymbolTable::SymbolTable()
{
	mParent = NULL;
}

SymbolTable::SymbolTable(SymbolTable* parent)
{
	mParent = parent;
}

SymbolTable::~SymbolTable()
{
	// @TODO Limpar símbolos. Verificar possíveis problemas.
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
