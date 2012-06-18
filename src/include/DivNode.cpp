#pragma once

#include "DivNode.h"
#include <cstdlib>

DivNode::DivNode(AstNode* left, AstNode* right)
{
	mLeft = left;
	mRight = right;
}

/* @TODO Implementar melhor, copy paste de SumNode */
ExprResult DivNode::eval()
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
				double resultValue = leftValue / rightValue;
				// Divisão inteira
				if (resultValue == (long)resultValue)
				{
					result.setValue(result.getLargerType(left, right), (long)resultValue);
				}
				else
				{
					result.setValue("double", resultValue);
				}
			}
			else if (right.isFloat())
			{
				double rightValue = right.getFloatValue();
				double resultValue = leftValue / rightValue;
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
				resultValue = leftValue / rightValue;
				result.setValue(left.getType(), resultValue);
			}
			else if (right.isFloat())
			{
				double rightValue = right.getFloatValue();
				resultValue = leftValue / rightValue;
				result.setValue(result.getLargerType(left, right), resultValue);
			}
		}
	}
	// Nenhuma operação pode ser realizada
	if (result.getType() == "void")
	{
		// @TODO Erro fatal, valores não numéricos
		std::exit(1);
	}
	return result;
}
