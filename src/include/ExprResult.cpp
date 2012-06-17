#pragma once

#include "ExprResult.h"

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

