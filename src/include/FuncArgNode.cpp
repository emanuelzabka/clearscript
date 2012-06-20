#include "FuncArgNode.h"
#include "ActivityReg.h"

FuncArgNode::FuncArgNode(std::string name, std::string type)
{
	mName = name;
	mType = type;
}

std::string FuncArgNode::getName()
{
	return mName;
}

std::string FuncArgNode::getType()
{
	return mType;
}

ExprResult FuncArgNode::eval()
{
	ExprResult result;
	ActivityReg* areg = ActivityReg::getInstance();
	SymbolTable* table = areg->top();
	table->add(new Symbol(mName, mType));
	return result;
}
