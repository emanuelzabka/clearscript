#pragma once

#include "CondNode.h"

class LogAndOpNode: public AstNode {
	protected:
		CondNode* mLeft;
		CondNode* mRight;
	public:
		LogAndOpNode(CondNode* left, CondNode* right);
		ExprResult eval();
};

