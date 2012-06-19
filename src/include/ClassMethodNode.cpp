#include "ClassMethodNode.h"

ClassMethodNode::ClassMethodNode(
	ClassNode* parent,
	std::string name,
	std::vector<FuncArgNode*> args,
	AstNode* body
)
{
	mParent = parent;
	mName = name;
	mArgs = args;
	mBody = body;
}
