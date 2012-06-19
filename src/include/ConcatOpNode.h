#pragma once

#include "BinaryOpNode.h"
#include "ExprResult.h"

class ConcatOpNode: public BinaryOpNode {
	public:
		ConcatOpNode(AstNode* left, AstNode* right);
		ExprResult eval();
};

