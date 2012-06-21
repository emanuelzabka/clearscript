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
		if (mThenBody != NULL)
		{
			mThenBody->eval();
		}
	}
	else if (mElseBody != NULL)
	{
		mElseBody->eval();
	}
	return result;
}

