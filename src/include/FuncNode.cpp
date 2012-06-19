#include "FuncNode.h"

FuncNode::FuncNode(std::string name, std::vector<FuncArgNode*> args, AstNode* body)
{
	mName = name;
	mArgs = args;
	mBody = body;
}
