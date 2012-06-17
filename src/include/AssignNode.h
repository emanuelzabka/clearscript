#pragma once

#include "BinaryOpNode.h"

class AssignNode: public BinaryOpNode {
	public:
		AssignNode(AstNode* left, AstNode* right);
};

