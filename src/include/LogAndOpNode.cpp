#include <cstdlib>
#include "LogAndOpNode.h"
#include "BoolVal.h"

LogAndOpNode::LogAndOpNode(CondNode* left, CondNode* right)
{
	mLeft = left;
	mRight = right;
}

ExprResult LogAndOpNode::eval()
{
	ExprResult left = mLeft->eval();
	ExprResult right = mRight->eval();
	ExprResult result("bool", (Val*)new BoolVal(left.getBoolVal() && right.getBoolVal()));
}
