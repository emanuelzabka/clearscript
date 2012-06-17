#pragma once

#include "IfNode.h"

IfNode::IfNode(AstNode* cond, AstNode* thenBody, AstNode* elseBody)
{
	mCond = cond;
	mThenBody = thenBody;
	mElseBody = elseBody;
}

