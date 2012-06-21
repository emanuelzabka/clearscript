#include "StmtListNode.h"

StmtListNode::StmtListNode(AstNode* left, AstNode* right)
{
	mLeft = left;
	mRight = right;
}

ExprResult StmtListNode::eval()
{
	ExprResult result;
	if (mLeft != NULL)
	{
		mLeft->eval();
	}
	if (mRight != NULL)
	{
		mRight->eval();
	}
	return result;
}

