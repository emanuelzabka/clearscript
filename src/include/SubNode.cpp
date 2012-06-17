#pragma once

#include "SubNode.h"

SubNode::SubNode(AstNode* left, AstNode* right)
{
	mLeft = left;
	mRight = right;
}
