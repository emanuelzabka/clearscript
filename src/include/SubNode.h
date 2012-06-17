#pragma once

#include "BinaryOpNode.h"

class SubNode: public BinaryOpNode {
	public:
		SubNode(AstNode* left, AstNode* right);
};

