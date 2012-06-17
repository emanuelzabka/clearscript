#pragma once

#include "MulNode.h"

MulNode::MulNode(AstNode* left, AstNode* right)
{
	mLeft = left;
	mRight = right;
}
