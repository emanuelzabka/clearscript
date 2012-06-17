#pragma once

#include "ModNode.h"

ModNode::ModNode(AstNode* left, AstNode* right)
{
	mLeft = left;
	mRight = right;
}
