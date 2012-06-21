#include "LongConstNode.h"
#include "LongVal.h"

LongConstNode::LongConstNode(long value)
{
	mValue = value;
}

ExprResult LongConstNode::eval()
{
	ExprResult result("long", (Val*)new LongVal(mValue));
	return result;
}
