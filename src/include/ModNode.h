#pragma once

#include "BinaryOpNode.h"

class ModNode: public BinaryOpNode {
	public:
		ModNode(AstNode* left, AstNode* right);
};

