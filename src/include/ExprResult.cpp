#pragma once

#include "ExprResult.h"
#include "IntVal.h"
#include "FloatVal.h"
#include "LongVal.h"
#include "DoubleVal.h"

ExprResult::ExprResult()
{
	mType = "void";
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

bool ExprResult::isNumeric(ExprResult& res)
{
	return isInteger(res) || isFloat(res);
}

bool ExprResult::isFloat(ExprResult& res)
{
	return
		res.getType() == "float" ||
		res.getType() == "double";
}

bool ExprResult::isInteger(ExprResult& res)
{
	return
		res.getType() == "int" ||
		res.getType() == "long";
}

long ExprResult::getIntegerValue(ExprResult& res)
{
	if (res.getType() == "int")
	{
		return ((IntVal*)res.getValue())->getValue();
	}
	else if (res.getType() == "long")
	{
		return ((LongVal*)res.getValue())->getValue();
	}
	// @TODO Erro chamada com parâmetros indevidos
	return 0;
}

double ExprResult::getFloatValue(ExprResult& res)
{
	if (res.getType() == "float")
	{
		return ((FloatVal*)res.getValue())->getValue();
	}
	else if (res.getType() == "double")
	{
		return ((DoubleVal*)res.getValue())->getValue();
	}
	// @TODO Erro chamada com parâmetros indevidos
	return 0;
}
