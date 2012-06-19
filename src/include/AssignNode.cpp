#include <string>
#include "AssignNode.h"

AssignNode::AssignNode(IdentifierNode* target, AstNode* value)
{
	mTarget = target;
	mValue = value;
}

