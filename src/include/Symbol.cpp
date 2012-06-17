#pragma once

#include "Symbol.h"

Symbol::Symbol(std::string name)
{
	mName = name;
}

std::string Symbol::getType()
{
	return mType;
}

void Symbol::setType(std::string type)
{
	mType = type;
}

Val* Symbol::getValue()
{
	return mValue;
}

void Symbol::setValue(Val* value)
{
	mValue = value;
}
