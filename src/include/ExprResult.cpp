#include "ExprResult.h"
#include "IntVal.h"
#include "FloatVal.h"
#include "LongVal.h"
#include "DoubleVal.h"
#include "BoolVal.h"
#include "StringVal.h"

ExprResult::ExprResult()
{
	mType = "void";
	mValue = NULL;
}

ExprResult::ExprResult(std::string type, Val* value)
{
	mType = type;
	mValue = value;
}

std::string ExprResult::getType()
{
	return mType;
}

Val* ExprResult::getValue()
{
	return mValue;
}

bool ExprResult::isNumeric()
{
	return isInteger() || isFloat();
}

bool ExprResult::isFloat()
{
	return
		getType() == "float" ||
		getType() == "double";
}

bool ExprResult::isInteger()
{
	return
		getType() == "int" ||
		getType() == "long";
}

long ExprResult::getIntegerValue()
{
	if (getType() == "int")
	{
		return ((IntVal*)getValue())->getValue();
	}
	else if (getType() == "long")
	{
		return ((LongVal*)getValue())->getValue();
	}
	// @TODO Erro chamada com parâmetros indevidos
	return 0;
}

double ExprResult::getFloatValue()
{
	if (getType() == "float")
	{
		return ((FloatVal*)getValue())->getValue();
	}
	else if (getType() == "double")
	{
		return ((DoubleVal*)getValue())->getValue();
	}
	// @TODO Erro chamada com parâmetros indevidos
	return 0;
}

std::string ExprResult::getLargerType(ExprResult& res1, ExprResult& res2)
{
	std::string result;
	if (res1.isFloat())
	{
		if (!res2.isFloat())
		{
			result = res1.getType();
		}
		else if (res1.getType() == "double")
		{
			result = "double";
		}
		else
		{
			result = res2.getType();
		}
	}
	else if (res1.isInteger())
	{
		if (res2.isInteger())
		{
			if (res1.getType() == "long")
			{
				result = "long";
			}
			else
			{
				result = res2.getType();
			}
		}
		else if (res2.isFloat())
		{
			result = res2.getType();
		}
	}
	return result;
}

void ExprResult::setValue(Val* value)
{
	mValue = value;
}

void ExprResult::setValue(std::string type, long value)
{
	if (type == "int")
	{
		mValue = (Val*)new IntVal(value);
		mType = type;
	}
	else if (type == "long")
	{
		mValue = (Val*)new LongVal(value);
		mType = type;
	}
}

void ExprResult::setValue(std::string type, double value)
{
	if (type == "float")
	{
		mValue = (Val*)new FloatVal(value);
		mType = type;
	}
	else if (type == "double")
	{
		mValue = (Val*)new DoubleVal(value);
		mType = type;
	}
}

void ExprResult::setType(std::string type)
{
	mType = type;
}

bool ExprResult::getBoolVal()
{
	bool result = false;
	if (getType() == "bool")
	{
		result = ((BoolVal*)getValue())->getValue();
	}
	if (isInteger())
	{
		result = (bool)getIntegerValue();
	}
	else if (isFloat())
	{
		result = (bool)getFloatValue();
	}
	else if (getType() == "string")
	{
		result = !((StringVal*)getValue())->getValue().empty();
	}
	return result;
}

