#include "AssignNode.h"

AssignNode::AssignNode(AstNode* left, AstNode* right)
{
	mLeft = left;
	mRight = right;
}

