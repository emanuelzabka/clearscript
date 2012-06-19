#include "ActivityRegs.h"

void ActivityRegs::push(SymbolTable* table)
{
	mTables.push(table);
}

void ActivityRegs::pop()
{
	mTables.pop();
}

SymbolTable* ActivityRegs::top()
{
	return mTables.top();
}

