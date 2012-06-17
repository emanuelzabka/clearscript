#pragma once

#include "BinaryOpNode.h"

class PowNode: public BinaryOpNode {
	public:
		PowNode(AstNode* left, AstNode* right);
};

