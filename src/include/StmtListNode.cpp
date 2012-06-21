#include "StmtListNode.h"

StmtListNode::StmtListNode(AstNode* left, AstNode* right)
{
	mLeft = left;
	mRight = right;
}

ExprResult StmtListNode::eval()
{
	mLeft->eval();
	mRight->eval();
}

