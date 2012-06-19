#pragma once

#include <string>
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
		bool compare(std::string left, std::string right);
		bool compare(long left, long right);
		bool compare(double left, double right);
		bool compare(long left, double right);
		bool compare(double right, long left);
	public:
		CondNode(AstNode* left, AstNode* right, ConditionType type);
		ExprResult eval();
};

