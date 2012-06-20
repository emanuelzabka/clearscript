#include "ActivityRegs.h"

ActivityRegs* ActivityRegs::mInstance = NULL;

ActivityRegs::ActivityRegs()
{
	// Cria escopo global geral por padrão
	push(new SymbolTable());
}

void ActivityRegs::push(SymbolTable* table)
{
	mTables.push_back(table);
}

void ActivityRegs::pop()
{
	mTables.pop_back();
}

SymbolTable* ActivityRegs::top()
{
	return mTables.back();
}

ActivityRegs* ActivityRegs::getInstance()
{
	if (!mInstance)
	{
		mInstance = new ActivityRegs();
	}
	return mInstance;
}

Symbol* ActivityRegs::getUserType(std::string type)
{
	// Tipos são guardados sempre na tabela de símbolos global
	SymbolTable* table = mTables.front();
	Symbol* entry = table->get(type);
	if (entry && entry->getType() == "type")
	{
		return entry;
	}
	return NULL;
}

bool ActivityRegs::isBuiltinType(std::string type)
{
	return
		type == "string" ||
		type == "int"    ||
		type == "long"   ||
		type == "float"  ||
		type == "double" ||
		type == "bool";
}
