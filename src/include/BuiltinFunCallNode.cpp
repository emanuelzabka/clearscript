#include <iostream>
#include "BuiltinFunCallNode.h"
#include "IntVal.h"
#include "LongVal.h"
#include "FloatVal.h"
#include "DoubleVal.h"
#include "BoolVal.h"
#include "StringVal.h"

BuiltinFunCallNode::BuiltinFunCallNode(BuiltinFunction type, std::vector<AstNode*> args)
{
	mType = type;
	mArgs = args;
}

void BuiltinFunCallNode::evalPrint(ExprResult& res)
{
	std::string type = res.getType();
	for (int i = 0; i < mArgs.size(); i++)
	{
		ExprResult argVal = mArgs[i]->eval();
		if (argVal.getType() == "int")
		{
			std::cout << ((IntVal*)argVal.getValue())->getValue();
		}
		else if (argVal.getType() == "long")
		{
			std::cout << ((LongVal*)argVal.getValue())->getValue();
		}
		else if (argVal.getType() == "float")
		{
			std::cout << ((FloatVal*)argVal.getValue())->getValue();
		}
		else if (argVal.getType() == "double")
		{
			std::cout << ((DoubleVal*)argVal.getValue())->getValue();
		}
		else if (argVal.getType() == "bool")
		{
			std::cout << ((BoolVal*)argVal.getValue())->getValue();
		}
		else if (argVal.getType() == "string")
		{
			std::cout << ((StringVal*)argVal.getValue())->getValue();
		}
		else if (argVal.getType() == "object")
		{
			std::cout << "<Object>";
		}
	}
}

ExprResult BuiltinFunCallNode::eval()
{
	ExprResult result;
	switch (mType)
	{
		case BF_PRINT:
			evalPrint(result);
			break;
	}
	return result;
}
