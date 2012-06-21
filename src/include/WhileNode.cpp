#include "WhileNode.h"

WhileNode::WhileNode(AstNode* cond, AstNode* body)
{
	mCond = cond;
	mBody = body;
}

ExprResult WhileNode::eval()
{
	ExprResult result;
	while (mCond->eval().getBoolVal())
	{
		if (mBody != NULL)
		{
			mBody->eval();
		}
	}
	return result;
}
