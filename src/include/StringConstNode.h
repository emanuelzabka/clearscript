#pragma once

#include "AstNode.h"
#include <string>

class StringConstNode: public AstNode {
	protected:
		std::string mValue;
	public:
		StringConstNode(std::string value);
		ExprResult eval();
};
