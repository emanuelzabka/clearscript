#pragma once

#include "BinaryOpNode.h"

class DivNode: public BinaryOpNode {
	public:
		DivNode(AstNode* left, AstNode* right);
};

