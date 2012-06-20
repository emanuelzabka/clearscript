#pragma once

#include <string>
#include "AstNode.h"

class FuncArgNode: public AstNode {
	protected:
		std::string mName;
		std::string mType;
		/* @TODO default value */
	public:
		FuncArgNode(std::string name, std::string type);
		ExprResult eval();
};

