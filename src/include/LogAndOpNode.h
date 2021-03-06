#pragma once

#include "AstNode.h"

class LogAndOpNode: public AstNode {
	protected:
		AstNode* mLeft;
		AstNode* mRight;
	public:
		LogAndOpNode(AstNode* left, AstNode* right);
		ExprResult eval();
};

