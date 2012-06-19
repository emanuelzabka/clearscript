#pragma once

#include "AstNode.h"
#include "ExprResult.h"
#include <string>

// @TODO Esse node terá de ser mudado quando implementar orientação
// a objeto <objeto>.<id>
class IdentifierNode: public AstNode {
	protected:
		std::string mName;
	public:
		IdentifierNode(std::string name);
		ExprResult eval();
};

