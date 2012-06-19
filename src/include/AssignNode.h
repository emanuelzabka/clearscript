#pragma once

#include <string>
#include "BinaryOpNode.h"
#include "Identifier.h"

class AssignNode: public AstNode {
	protected:
		IdentifierNode* mTarget;
		AstNode* mValue;
	public:
		AssignNode(IdentifierNode* target, AstNode* value);
};

