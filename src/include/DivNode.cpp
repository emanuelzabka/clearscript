#pragma once

#include "DivNode.h"

DivNode::DivNode(AstNode* left, AstNode* right)
{
	mLeft = left;
	mRight = right;
}
