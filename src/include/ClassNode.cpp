#pragma once

#include "ClassNode.h"

ClassNode::ClassNode(std::string name, AstNode* body)
{
	mName = name;
	mBody = body;
}
