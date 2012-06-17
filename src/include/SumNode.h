#pragma once

#include "BinaryOpNode.h"

class SumNode: public BinaryOpNode {
	public:
		SumNode(AstNode* left, AstNode* right);
};

