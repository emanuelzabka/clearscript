#include "ConcatOpNode.h"
#include "StringVal.h"
#include "Log.h"

ConcatOpNode::ConcatOpNode(AstNode* left, AstNode* right)
{
	mLeft = left;
	mRight = right;
}

ExprResult ConcatOpNode::eval()
{
	ExprResult result;
	ExprResult left = mLeft->eval();
	ExprResult right = mRight->eval();
	// @TODO Realizar cast automáticos de tipos
	if (left.getType() == "string" && right.getType() == "string")
	{
		StringVal* leftVal = (StringVal*)left.getValue();
		StringVal* rightVal = (StringVal*)right.getValue();
		result.setType("string");
		result.setValue((Val*)new StringVal(leftVal->getValue() + rightVal->getValue()));
	}
	else
	{
		Log::fatal("Uso incorreto do operador de concatenação, tipos incorretos");
	}
	return result;
}
