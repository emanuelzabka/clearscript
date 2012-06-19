#include "WhileNode.h"

WhileNode::WhileNode(AstNode* cond, AstNode* body)
{
	mCond = cond;
	mBody = body;
}

