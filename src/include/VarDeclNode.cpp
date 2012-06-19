#include "VarDeclNode.h"

VarDeclNode::VarDeclNode(std::string type, std::string name)
{
	mType = type;
	mName = name;
}

ExprResult VarDeclNode::eval()
{
	//@TODO Registra variável no registro de ativação atual
}
