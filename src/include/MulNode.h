#pragma once

#include "BinaryOpNode.h"

class MulNode: public BinaryOpNode {
	public:
		MulNode(AstNode* left, AstNode* right);
		ExprResult eval();
};

