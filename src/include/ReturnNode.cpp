#include "ReturnNode.h"
#include "ActivationReg.h"
#include "SymbolTable.h"
#include "Symbol.h"

ReturnNode::ReturnNode(AstNode* value)
{
	mValue = value;
}

ExprResult ReturnNode::eval()
{
	ExprResult result;
	ExprResult value = mValue->eval();
	ActivationReg* areg = ActivationReg::getInstance();
	SymbolTable* table = areg->top();
	Symbol* ret = new Symbol("--return", value.getType(), true);
	ret->setValue(value.getValue());
	table->add(ret);
	return result;
}

