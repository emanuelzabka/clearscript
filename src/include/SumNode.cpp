#pragma once

#include "SumNode.h"

SumNode::SumNode(AstNode* left, AstNode* right)
{
	mLeft = left;
	mRight = right;
}

