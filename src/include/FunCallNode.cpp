#include <cstdlib>
#include <vector>
#include "FunCallNode.h"
#include "ActivityReg.h"
#include "SymbolTable.h"
#include "FuncNode.h"
#include "FuncArgNode.h"
#include "SymbolTable.h"

FunCallNode::FunCallNode(std::string name, std::vector<AstNode*> args)
{
	mName = name;
	mArgs = args;
}

ExprResult FunCallNode::eval()
{
	ExprResult result;
	ActivityReg* areg = ActivityReg::getInstance();
	SymbolTable* table = areg->global();
	Symbol* sym = table->get(mName);
	if (sym != NULL && sym->getType() == "function")
	{
		// Tabela de símbolos de escopo local
		SymbolTable* local = areg->top();
		FuncNode* func = (FuncNode*)sym->getNode();
		std::vector<FuncArgNode*> argDefs = func->getArgs();
		if (argDefs.size() != mArgs.size())
		{
			// @TODO Erro fatal, contagem incorreta de parâmetros
			exit(1);
		}
		// Pegar parâmetros
		for (int i = 0; i < mArgs.size(); i++)
		{
			// Cria entradas no registro de ativação local
			argDefs[i]->eval();
			// Calcula valor para argumento
			ExprResult argValue = mArgs[i]->eval();
			// Seta valor do símbolo na tabela local
			local->get(argDefs[i]->getName())->setValue(argValue.getType(), argValue.getValue());
		}
		// Executar eval no corpo da função
		result = func->getBody()->eval();
	}
	else
	{
		// @TODO Erro fatal, chamada de função não existente
		exit(1);
	}
	return result;
}

