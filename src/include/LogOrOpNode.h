#pragma once

#include "AstNode.h"

class LogOrOpNode: public AstNode {
	protected:
		AstNode* mLeft;
		AstNode* mRight;
	public:
		LogOrOpNode(AstNode* left, AstNode* right);
		ExprResult eval();
};

