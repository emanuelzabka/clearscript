#pragma once

#include "AstNode.h"

class StmtListNode: public AstNode {
	protected:
		AstNode* mLeft;
		AstNode* mRight;
	public:
		StmtListNode(AstNode* left, AstNode* right);
		ExprResult eval();
};

