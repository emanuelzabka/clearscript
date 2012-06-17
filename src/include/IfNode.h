#pragma once

#include "AstNode.h"

class IfNode: public AstNode {
	protected:
		AstNode* mCond;
		AstNode* mThenBody;
		AstNode* mElseBody;
	public:
		IfNode(AstNode* cond, AstNode* thenBody, AstNode* elseBody);
};

