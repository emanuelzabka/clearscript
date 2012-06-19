#include <cstdlib>
#include <string>
#include "CondNode.h"
#include "BoolVal.h"
#include "StringVal.h"

CondNode::CondNode(AstNode* left, AstNode* right, ConditionType type)
{
	mLeft = left;
	mRight = right;
	mType = type;
}

bool CondNode::compare(std::string left, std::string right)
{
	switch (mType)
	{
		case CT_EQUAL:
			return left == right;
		case CT_NEQUAL:
			return left != right;
		case CT_GT:
			return left > right;
		case CT_LT:
			return left < right;
		case CT_GTE:
			return left >= right;
		case CT_LTE:
			return left <= right;
	}
	return false;
}

bool CondNode::compare(long left, long right)
{
	switch (mType)
	{
		case CT_EQUAL:
			return left == right;
		case CT_NEQUAL:
			return left != right;
		case CT_GT:
			return left > right;
		case CT_LT:
			return left < right;
		case CT_GTE:
			return left >= right;
		case CT_LTE:
			return left <= right;
	}
	return false;
}

bool CondNode::compare(double left, double right)
{
	switch (mType)
	{
		case CT_EQUAL:
			return left == right;
		case CT_NEQUAL:
			return left != right;
		case CT_GT:
			return left > right;
		case CT_LT:
			return left < right;
		case CT_GTE:
			return left >= right;
		case CT_LTE:
			return left <= right;
	}
	return false;
}

bool CondNode::compare(long left, double right)
{
	switch (mType)
	{
		case CT_EQUAL:
			return left == right;
		case CT_NEQUAL:
			return left != right;
		case CT_GT:
			return left > right;
		case CT_LT:
			return left < right;
		case CT_GTE:
			return left >= right;
		case CT_LTE:
			return left <= right;
	}
	return false;
}

bool CondNode::compare(double right, long left)
{
	switch (mType)
	{
		case CT_EQUAL:
			return left == right;
		case CT_NEQUAL:
			return left != right;
		case CT_GT:
			return left > right;
		case CT_LT:
			return left < right;
		case CT_GTE:
			return left >= right;
		case CT_LTE:
			return left <= right;
	}
	return false;
}

ExprResult CondNode::eval()
{
	ExprResult result;
	ExprResult left = mLeft->eval();
	ExprResult right = mRight->eval();
	// @TODO Realizar cast automático para string nos casos necessários
	if (left.isNumeric() && right.isNumeric())
	{
		result.setType("bool");
		if (left.isInteger())
		{
			long leftVal = left.getIntegerValue();
			if (right.isInteger())
			{
				long rightVal = right.getIntegerValue();
				result.setValue((Val*)new BoolVal(compare(leftVal, rightVal)));
			}
			else
			{
				double rightVal = right.getFloatValue();
				result.setValue((Val*)new BoolVal(compare(leftVal, rightVal)));
			}
		}
		else
		{
			double leftVal = left.getFloatValue();
			if (right.isInteger())
			{
				long rightVal = right.getIntegerValue();
				result.setValue((Val*)new BoolVal(compare(leftVal, rightVal)));
			}
			else
			{
				double rightVal = right.getFloatValue();
				result.setValue((Val*)new BoolVal(compare(leftVal, rightVal)));
			}
		}
	}
	else if (left.getType() == "string" && right.getType() == "string")
	{
		result.setType("bool");
		std::string leftVal = ((StringVal*)left.getValue())->getValue();
		std::string rightVal = ((StringVal*)right.getValue())->getValue();
		result.setValue((Val*)new BoolVal(compare(leftVal, rightVal)));
	}
	if (result.getType() == "void")
	{
		// @TODO Erro fatal, tipos incopatíveis para comparação
		exit(1);
	}
	return result;
}
