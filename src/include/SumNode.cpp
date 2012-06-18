#pragma once

#include "SumNode.h"

SumNode::SumNode(AstNode* left, AstNode* right)
{
	mLeft = left;
	mRight = right;
}

ExprResult SumNode::eval()
{
	ExprResult result;
	ExprResult left = mLeft->eval();
	ExprResult right = mRight->eval();
	if (result.isNumeric(left) && result.isNumeric(right))
	{
		if (result.isInteger(left))
		{
			long leftValue = result.getIntegerValue(left);
			if (result.isInteger(right))
			{
				long rightValue = result.getIntegerValue(right);
			}
		}
	}
	else
	{
		// @TODO Erro fatal, valores não numéricos
		exit(0);
	}
	return result;
}

