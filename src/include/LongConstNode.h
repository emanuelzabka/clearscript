#pragma once

#include "AstNode.h"

class LongConstNode: public AstNode {
	protected:
		long mValue;
	public:
		LongConstNode(long value);
		ExprResult eval();
};
