#include "IfNode.h"

IfNode::IfNode(AstNode* cond, AstNode* thenBody, AstNode* elseBody)
{
	mCond = cond;
	mThenBody = thenBody;
	mElseBody = elseBody;
}

ExprResult IfNode::eval()
{
	ExprResult result;
	ExprResult cond = mCond->eval();
	if (cond.getBoolVal())
	{
		mThenBody->eval();
	}
	else
	{
		mElseBody->eval();
	}
	return result;
}

