#pragma once

#include "AstNode.h"
#include <string>

class VarDeclNode: public AstNode {
	protected:
		std::string mType;
		std::string mName;
	public:
		VarDeclNode(std::string type, std::string name);
		ExprResult eval();
};

