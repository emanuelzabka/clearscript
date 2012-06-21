#include "StringConstNode.h"
#include "StringVal.h"

StringConstNode::StringConstNode(std::string value)
{
	mValue = value;
}

ExprResult StringConstNode::eval()
{
	ExprResult result("string", (Val*)new StringVal(mValue));
	return result;
}

