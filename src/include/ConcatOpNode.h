#pragma once

#include "BinaryOpNode.h"

class ConcatOpNode: public BinaryOpNode {
	public:
		ConcatOpNode(AstNode* left, AstNode* right);
		ExprResult eval();
};

