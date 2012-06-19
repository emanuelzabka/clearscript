#include <cstdlib>
#include "LogOrOpNode.h"
#include "BoolVal.h"

LogOrOpNode::LogOrOpNode(CondNode* left, CondNode* right)
{
	mLeft = left;
	mRight = right;
}

ExprResult LogOrOpNode::eval()
{
	ExprResult left = mLeft->eval();
	ExprResult right = mRight->eval();
	ExprResult result("bool", (Val*)new BoolVal(left.getBoolVal() || right.getBoolVal()));
}
