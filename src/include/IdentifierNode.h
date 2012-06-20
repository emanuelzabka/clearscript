#pragma once

#include <string>
#include "AstNode.h"
#include "Symbol.h"

// @TODO Esse node terá de ser mudado quando implementar orientação
// a objeto <objeto>.<id>
class IdentifierNode: public AstNode {
	protected:
		std::string mName;
	public:
		IdentifierNode(std::string name);
		ExprResult eval();
		Symbol* getSymbol();
};

