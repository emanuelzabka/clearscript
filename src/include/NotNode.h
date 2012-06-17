#pragma once

#include "AstNode.h"

class NotNode: public AstNode {
	protected:
		AstNode* mTarget;
	public:
		NotNode(AstNode* target);
};

