#pragma once

#include "AstNode.h"
#include <string>

class VarDeclNode: public AstNode {
	protected:
		std::string mType;
		std::string mName;
	public:
		VarDeclNode(std::string type, std::string name);
		std::string getName();
		std::string getType();
		ExprResult eval();
};

