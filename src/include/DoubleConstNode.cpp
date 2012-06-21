#include "DoubleConstNode.h"
#include "DoubleVal.h"

DoubleConstNode::DoubleConstNode(double value)
{
	mValue = value;
}

ExprResult DoubleConstNode::eval()
{
	ExprResult result("double", (Val*)new DoubleVal(mValue));
	return result;
}
