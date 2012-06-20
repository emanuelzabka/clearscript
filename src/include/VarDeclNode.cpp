#include <cstdlib>
#include "VarDeclNode.h"
#include "ActivationReg.h"
#include "Symbol.h"


VarDeclNode::VarDeclNode(std::string type, std::string name)
{
	mType = type;
	mName = name;
}

ExprResult VarDeclNode::eval()
{
	ActivationReg* areg = ActivationReg::getInstance();
	SymbolTable* table = areg->top();
	if (areg->isBuiltinType(mType))
	{
		Symbol* sym = table->get(mName);
		if (sym == NULL)
		{
			table->add(new Symbol(mName, mType));
		}
		else if (sym->getType() != mType)
		{
			// @TODO Redeclaração de variável dentro do mesmo escopo com tipos diferentes
			exit(1);
		}
	}
	else
	{
		Symbol* userType = areg->getUserType(mType);
		if (userType != NULL)
		{
			table->add(new Symbol(mName, mType));
		}
		else
		{
			// @TODO Erro fatal, tipo desconhecido
			exit(1);
		}
	}
	//@TODO Registra variável no registro de ativação atual
}
