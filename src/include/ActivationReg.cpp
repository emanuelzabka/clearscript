#include "ActivationReg.h"

ActivationReg* ActivationReg::mInstance = NULL;

ActivationReg::ActivationReg()
{
	// Cria escopo global geral por padrão
	push(new SymbolTable());
}

ActivationReg::~ActivationReg()
{
	// Chama destrutor para as tabelas de símbolos ainda presentes
	for (int i = 0; mTables.size(); i++)
	{
		delete mTables[i];
	}
}

void ActivationReg::push(SymbolTable* table)
{
	mTables.push_back(table);
}

void ActivationReg::pop()
{
	mTables.pop_back();
}

SymbolTable* ActivationReg::top()
{
	return mTables.back();
}

SymbolTable* ActivationReg::global()
{
	return mTables.front();
}

ActivationReg* ActivationReg::getInstance()
{
	if (!mInstance)
	{
		mInstance = new ActivationReg();
	}
	return mInstance;
}

Symbol* ActivationReg::getUserType(std::string type)
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

bool ActivationReg::isBuiltinType(std::string type)
{
	return
		type == "string" ||
		type == "int"    ||
		type == "long"   ||
		type == "float"  ||
		type == "double" ||
		type == "bool";
}
