#include "NotNode.h"
#include "BoolVal.h"
#include <cstdlib>

NotNode::NotNode(AstNode* target)
{
	mTarget = target;
}

ExprResult NotNode::eval()
{
	ExprResult result;
	ExprResult targetRes = mTarget->eval();
	if (targetRes.isNumeric())
	{
		if (targetRes.isFloat())
		{
			double value = targetRes.getFloatValue();
			result.setValue("int", (long)(value == 0 ? 1 : 0));
		}
		else if (targetRes.isInteger())
		{
			long value = targetRes.getIntegerValue();
			result.setValue("int", (long)(value == 0 ? 1 : 0));
		}
	}
	else if (targetRes.getType() == "bool")
	{
		bool value = ((BoolVal*)targetRes.getValue())->getValue();
		result.setType("bool");
		result.setValue((Val*)new BoolVal(!value));
	}
	else
	{
		// @TODO Erro fatal uso de tipo não numérico no not
		exit(1);
	}
	return result;
}
