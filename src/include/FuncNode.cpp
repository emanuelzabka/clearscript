#include "FuncNode.h"
#include "ActivationReg.h"
#include "SymbolTable.h"
#include "Symbol.h"

FuncNode::FuncNode(std::string name, std::string type, std::vector<FuncArgNode*> args, AstNode* body)
{
	mName = name;
	mType = type;
	mArgs = args;
	mBody = body;
}

FuncNode::~FuncNode()
{
	for (int i = 0; i < mArgs.size(); i++)
	{
		delete mArgs[i];
	}
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
	ActivationReg* areg = ActivationReg::getInstance();
	SymbolTable* table = areg->global();
	Symbol* sym = new Symbol(mName, "function");
	sym->setNode(this);
	table->add(sym);
	return result;
}
