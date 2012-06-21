#pragma once

#include "AstNode.h"

class DoubleConstNode: public AstNode {
	protected:
		double mValue;
	public:
		DoubleConstNode(double value);
		ExprResult eval();
};
