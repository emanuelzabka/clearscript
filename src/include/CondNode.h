#pragma once

#include "BinaryOpNode.h"

enum ConditionType {
	// Equal
	CT_EQUAL,
	// Not Equal
	CT_NEQUAL,
	// Greater Than
	CT_GT,
	// Less Than
	CT_LT,
	// Greater Than or Equal
	CT_GTE,
	// Less Than or Equal
	CT_LTE
};

class CondNode: public BinaryOpNode  {
	protected:
		ConditionType mType;
	public:
		CondNode(AstNode* left, AstNode* right, ConditionType type);
};

