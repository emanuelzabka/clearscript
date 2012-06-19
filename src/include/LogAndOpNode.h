#pragma once

#include "CondNode.h"
#include "ExprResult.h"

class LogAndOpNode: public AstNode {
	protected:
		CondNode* mLeft;
		CondNode* mRight;
	public:
		LogAndOpNode(CondNode* left, CondNode* right);
		ExprResult eval();
};

