#pragma once

#include "AstNode.h"

class WhileNode: public AstNode {
	protected:
		AstNode* mCond;
		AstNode* mBody;
	public:
		WhileNode(AstNode* cond, AstNode* body);
};

