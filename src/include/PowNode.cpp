#pragma once

#include "PowNode.h"

PowNode::PowNode(AstNode* left, AstNode* right)
{
	mLeft = left;
	mRight = right;
}
