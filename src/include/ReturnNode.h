#pragma once

#include "AstNode.h"

class ReturnNode: public AstNode {
	protected:
		AstNode* mValue;
	public:
		ReturnNode(AstNode* value);
		ExprResult eval();
};

