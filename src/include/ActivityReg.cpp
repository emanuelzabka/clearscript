#include "ActivityReg.h"

ActivityReg* ActivityReg::mInstance = NULL;

ActivityReg::ActivityReg()
{
	// Cria escopo global geral por padrão
	push(new SymbolTable());
}

void ActivityReg::push(SymbolTable* table)
{
	mTables.push_back(table);
}

void ActivityReg::pop()
{
	mTables.pop_back();
}

SymbolTable* ActivityReg::top()
{
	return mTables.back();
}

SymbolTable* ActivityReg::global()
{
	return mTables.front();
}

ActivityReg* ActivityReg::getInstance()
{
	if (!mInstance)
	{
		mInstance = new ActivityReg();
	}
	return mInstance;
}

Symbol* ActivityReg::getUserType(std::string type)
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

bool ActivityReg::isBuiltinType(std::string type)
{
	return
		type == "string" ||
		type == "int"    ||
		type == "long"   ||
		type == "float"  ||
		type == "double" ||
		type == "bool";
}
