#include "LogNotOpNode.h"
#include "BoolVal.h"

LogNotOpNode::LogNotOpNode(AstNode* target)
{
	mTarget = target;
}

ExprResult LogNotOpNode::eval()
{
	ExprResult targetRes = mTarget->eval();
	ExprResult result("bool", (Val*)new BoolVal(targetRes.getBoolVal()));
	return result;
}
