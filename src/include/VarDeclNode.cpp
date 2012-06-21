#include "VarDeclNode.h"
#include "ActivationReg.h"
#include "Symbol.h"
#include "Log.h"


VarDeclNode::VarDeclNode(std::string type, std::string name)
{
	mType = type;
	mName = name;
}

std::string VarDeclNode::getName()
{
	return mName;
}

std::string VarDeclNode::getType()
{
	return mType;
}

ExprResult VarDeclNode::eval()
{
	ExprResult result;
	ActivationReg* areg = ActivationReg::getInstance();
	SymbolTable* table = areg->top();
	if (areg->isBuiltinType(mType))
	{
		Symbol* sym = table->get(mName);
		if (sym == NULL)
		{
			table->add(new Symbol(mName, mType, true));
		}
		else if (sym->getType() != mType)
		{
			Log::fatal("Variável redeclarada com tipos diferentes dentro de mesmo escopo.");
		}
	}
	else
	{
		Symbol* userType = areg->getUserType(mType);
		if (userType != NULL)
		{
			table->add(new Symbol(mName, mType, true));
		}
		else
		{
			Log::fatal("Tipo desconhecido");
		}
	}
	return result;
}
