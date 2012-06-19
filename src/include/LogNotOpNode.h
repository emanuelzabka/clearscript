#pragma once

#include "AstNode.h"

class LogNotOpNode: public AstNode {
	protected:
		AstNode* mTarget;
	public:
		LogNotOpNode(AstNode* target);
		ExprResult eval();
};

