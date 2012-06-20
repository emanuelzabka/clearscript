#include "MulNode.h"
#include "Log.h"

MulNode::MulNode(AstNode* left, AstNode* right)
{
	mLeft = left;
	mRight = right;
}

/* @TODO Implementar melhor, copy paste de SumNode */
ExprResult MulNode::eval()
{
	ExprResult result;
	ExprResult left = mLeft->eval();
	ExprResult right = mRight->eval();
	if (left.isNumeric() && right.isNumeric())
	{
		if (left.isInteger())
		{
			long leftValue = left.getIntegerValue();
			if (right.isInteger())
			{
				long rightValue = right.getIntegerValue();
				long resultValue = leftValue * rightValue;
				result.setValue(result.getLargerType(left, right), resultValue);
			}
			else if (right.isFloat())
			{
				double rightValue = right.getFloatValue();
				double resultValue = leftValue * rightValue;
				result.setValue(result.getLargerType(left, right), resultValue);
			}
		}
		else if (left.isFloat())
		{
			double leftValue = left.getFloatValue();
			double resultValue = leftValue;
			if (right.isInteger())
			{
				long rightValue = right.getIntegerValue();
				resultValue *= rightValue;
			}
			else if (right.isFloat())
			{
				double rightValue = right.getFloatValue();
				resultValue *= rightValue;
			}
			result.setValue(result.getLargerType(left, right), resultValue);
		}
	}
	// Nenhuma operação pode ser realizada
	if (result.getType() == "void")
	{
		Log::fatal("Uso de multiplicação com tipos não numéricos");
	}
	return result;
}

