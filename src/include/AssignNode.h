#pragma once

#include <string>
#include "BinaryOpNode.h"
#include "IdentifierNode.h"

class AssignNode: public AstNode {
	protected:
		IdentifierNode* mTarget;
		AstNode* mValue;
	public:
		AssignNode(IdentifierNode* target, AstNode* value);
		ExprResult eval();
};

