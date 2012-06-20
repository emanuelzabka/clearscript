#include <cstdlib>
#include "VarDeclNode.h"
#include "ActivationReg.h"


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
		if (table->get(mName) == NULL)
		{
			table->add(new Symbol(mName, mType));
		}
		else
		{
			// @TODO Redeclaração de variável dentro do mesmo escopo
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
