#include <cstdlib>
#include "IdentifierNode.h"
#include "ActivityReg.h"
#include "SymbolTable.h"
#include "Symbol.h"

IdentifierNode::IdentifierNode(std::string name)
{
	mName = name;
}

ExprResult IdentifierNode::eval()
{
	ExprResult result;
	ActivityReg* areg = ActivityReg::getInstance();
	SymbolTable* table = areg->top();
	Symbol* sym = table->get(mName);
	if (sym != NULL && sym->isVar())
	{
		result.setType(sym->getType());
		result.setValue(sym->getValue());
	}
	else
	{
		// @TODO Erro fatal uso de identificador não definido
		exit(1);
	}
	// Buscar símbolo nas tabelas de símbolo
	// Retornar seu valor com o tipo respectivo
	return result;
}

Symbol* IdentifierNode::getSymbol()
{
	ActivityReg* areg = ActivityReg::getInstance();
	SymbolTable* table = areg->top();
	Symbol* sym = table->get(mName);
	if (sym->isVar())
	{
		return sym;
	}
	return NULL;
}

