#pragma once

#include "CondNode.h"

CondNode::CondNode(AstNode* left, AstNode* right, ConditionType type)
{
	mLeft = left;
	mRight = right;
	mType = type;
}

