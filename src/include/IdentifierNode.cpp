#include "IdentifierNode.h"

IdentifierNode::IdentifierNode(std::string name)
{
	mName = name;
}

ExprResult IdentifierNode::eval()
{
	// Buscar símbolo nas tabelas de símbolo
	// Retornar seu valor com o tipo respectivo
}
