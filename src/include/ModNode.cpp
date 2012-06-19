#include "ModNode.h"
#include <cstdlib>

ModNode::ModNode(AstNode* left, AstNode* right)
{
	mLeft = left;
	mRight = right;
}

/* @TODO Implementar melhor, copy paste de SumNode com poucas diferenças */
ExprResult ModNode::eval()
{
	ExprResult result;
	ExprResult left = mLeft->eval();
	ExprResult right = mRight->eval();
	if (left.isNumeric() && right.isNumeric())
	{
		if (left.isInteger())
		{
			long leftValue = left.getIntegerValue();
			long resultValue;
			if (right.isInteger())
			{
				long rightValue = right.getIntegerValue();
				resultValue = leftValue % rightValue;
				result.setValue("long", resultValue);
			}
			else if (right.isFloat())
			{
				long rightValue = (long)right.getFloatValue();
				resultValue = leftValue % rightValue;
				result.setValue("long", resultValue);
			}
		}
		else if (left.isFloat())
		{
			long leftValue = (long)left.getFloatValue();
			long resultValue;
			if (right.isInteger())
			{
				long rightValue = right.getIntegerValue();
				resultValue = leftValue % rightValue;
			}
			else if (right.isFloat())
			{
				long rightValue = (long)right.getFloatValue();
				resultValue = leftValue % rightValue;
			}
			result.setValue("long", resultValue);
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

