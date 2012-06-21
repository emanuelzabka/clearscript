#include "LogOrOpNode.h"
#include "BoolVal.h"

LogOrOpNode::LogOrOpNode(AstNode* left, AstNode* right)
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
