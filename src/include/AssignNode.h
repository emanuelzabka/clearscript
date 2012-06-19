#pragma once

#include <string>
#include "BinaryOpNode.h"
#include "Identifier.h"

class AssignNode: public AstNode {
	protected:
		Identifier* mTarget;
		AstNode* mValue;
	public:
		AssignNode(Identifier* target, AstNode* value);
};

