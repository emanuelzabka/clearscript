#include "StmtListNode.h"

StmtListNode::StmtListNode(AstNode* left, AstNode* right)
{
	mLeft = left;
	mRight = right;
}

ExprResult StmtListNode::eval()
{
	ExprResult result;
	mLeft->eval();
	if (mRight != NULL)
	{
		mRight->eval();
	}
	return result;
}

