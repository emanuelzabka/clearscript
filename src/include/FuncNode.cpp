#include "FuncNode.h"
#include "ActivityReg.h"
#include "SymbolTable.h"
#include "Symbol.h"

FuncNode::FuncNode(std::string name, std::string type, std::vector<FuncArgNode*> args, AstNode* body)
{
	mName = name;
	mType = type;
	mArgs = args;
	mBody = body;
}

std::string FuncNode::getType()
{
	return mType;
}

std::vector<FuncArgNode*>& FuncNode::getArgs()
{
	return mArgs;
}

AstNode* FuncNode::getBody()
{
	return mBody;
}

ExprResult FuncNode::eval()
{
	ExprResult result;
	ActivityReg* areg = ActivityReg::getInstance();
	SymbolTable* table = areg->global();
	Symbol* sym = new Symbol(mName, "function");
	sym->setNode(this);
	table->add(sym);
	return result;
}
