#pragma once

#include "AstNode.h"

class BinaryOpNode: public AstNode {
	protected:
		AstNode* mLeft;
		AstNode* mRight;
};

