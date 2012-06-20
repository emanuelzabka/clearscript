#include <cstdlib>
#include "FunCallNode.h"
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
		// Pegar parâmetros
		// Chamar eval de cada um
		// Setar valor de cada um conforme parâmetros passados
		// Executar eval no corpo da função
	}
	else
	{
		// @TODO Erro fatal, chamada de função não existente
		exit(1);
	}

	return result;
}

