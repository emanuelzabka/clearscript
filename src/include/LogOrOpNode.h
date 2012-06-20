#pragma once

#include "CondNode.h"

class LogOrOpNode: public AstNode {
	protected:
		CondNode* mLeft;
		CondNode* mRight;
	public:
		LogOrOpNode(CondNode* left, CondNode* right);
		ExprResult eval();
};

