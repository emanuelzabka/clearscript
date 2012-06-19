#include <string>
#include "AssignNode.h"

AssignNode::AssignNode(Identifier* target, AstNode* value)
{
	mTarget = target;
	mValue = value;
}

