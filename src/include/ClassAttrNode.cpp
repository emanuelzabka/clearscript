#include "ClassAttrNode.h"

ClassAttrNode::ClassAttrNode(
	ClassNode* parent,
	std::string name,
	std::string type,
	VisModifier visibility
)
{
	mParent = parent;
	mName = name;
	mType = type;
	mVisibility = visibility;
}
