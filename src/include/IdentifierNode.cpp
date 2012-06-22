#include "IdentifierNode.h"
#include "ActivationReg.h"
#include "SymbolTable.h"
#include "Symbol.h"
#include "Log.h"

IdentifierNode::IdentifierNode(std::string name)
{
	mName = name;
}

ExprResult IdentifierNode::eval()
{
	ExprResult result;
	ActivationReg* areg = ActivationReg::getInstance();
	SymbolTable* table = areg->top();
	Symbol* sym = table->get(mName);
	if (sym != NULL && sym->isVar())
	{
		result.setType(sym->getType());
		result.setValue(sym->getValue());
	}
	else
	{
		Log::fatal("Uso de identificador não definido");
	}
	return result;
}

Symbol* IdentifierNode::getSymbol()
{
	ActivationReg* areg = ActivationReg::getInstance();
	SymbolTable* table = areg->top();
	Symbol* sym = table->get(mName);
	if (sym != NULL && sym->isVar())
	{
		return sym;
	}
	return NULL;
}

std::string IdentifierNode::getName()
{
	return mName;
}

