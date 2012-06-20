#include <vector>
#include "FunCallNode.h"
#include "ActivationReg.h"
#include "SymbolTable.h"
#include "FuncNode.h"
#include "FuncArgNode.h"
#include "SymbolTable.h"
#include "Log.h"

FunCallNode::FunCallNode(std::string name, std::vector<AstNode*> args)
{
	mName = name;
	mArgs = args;
}

FunCallNode::~FunCallNode()
{
	for (int i = 0; i < mArgs.size(); i++)
	{
		delete mArgs[i];
	}
}

ExprResult FunCallNode::eval()
{
	ExprResult result;
	ActivationReg* areg = ActivationReg::getInstance();
	SymbolTable* table = areg->global();
	Symbol* sym = table->get(mName);
	if (sym != NULL && sym->getType() == "function")
	{
		// Tabela de símbolos de escopo local
		SymbolTable* local = areg->top();
		SymbolTable* new_table = new SymbolTable();
		// Empilha nova tabela de símbolos no gerenciador de registros de ativação
		areg->push(new_table);
		FuncNode* func = (FuncNode*)sym->getNode();
		std::vector<FuncArgNode*> argDefs = func->getArgs();
		if (argDefs.size() != mArgs.size())
		{
			Log::fatal("Contagem incorreta de parâmetros");
		}
		// Pegar parâmetros
		for (int i = 0; i < mArgs.size(); i++)
		{
			// Cria entradas no registro de ativação local à função
			argDefs[i]->eval();
			// Calcula valor para argumento
			ExprResult argValue = mArgs[i]->eval();
			// Seta valor do símbolo na tabela local à função
			new_table->get(argDefs[i]->getName())
				->setValue(argValue.getType(), argValue.getValue());
		}
		// Executar eval no corpo da função
		result = func->getBody()->eval();
		areg->pop();
		delete new_table;
	}
	else
	{
		Log::fatal("Função não definida");
	}
	return result;
}

