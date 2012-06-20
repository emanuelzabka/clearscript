#include <cstdlib>
#include "Symbol.h"

Symbol::Symbol(std::string name, std::string type)
{
	mName = name;
	mType = type;
	mVar = false;
}

Symbol::Symbol(std::string name, std::string type, bool var)
{
	mName = name;
	mType = type;
	mVar = var;
}

bool Symbol::isVar()
{
	return mVar;
}

std::string Symbol::getName()
{
	return mName;
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

void Symbol::setValue(IntVal* value)
{
	if (mType == "int")
	{
		((IntVal*)mValue)->setValue(value->getValue());
	}
	else if (mType == "long")
	{
		((LongVal*)mValue)->setValue((long)value->getValue());
	}
	else if (mType == "double")
	{
		((DoubleVal*)mValue)->setValue((double)value->getValue());
	}
	else if (mType == "float")
	{
		((FloatVal*)mValue)->setValue((float)value->getValue());
	}
	else if (mType == "bool")
	{
		((BoolVal*)mValue)->setValue((bool)value->getValue());
	}
	else
	{
		// @TODO Erro fatal, atribuição com valor incorreto
		exit(1);
	}
}

void Symbol::setValue(LongVal* value)
{
	if (mType == "int")
	{
		((IntVal*)mValue)->setValue((int)value->getValue());
	}
	else if (mType == "long")
	{
		((LongVal*)mValue)->setValue(value->getValue());
	}
	else if (mType == "double")
	{
		((DoubleVal*)mValue)->setValue((double)value->getValue());
	}
	else if (mType == "float")
	{
		((FloatVal*)mValue)->setValue((float)value->getValue());
	}
	else if (mType == "bool")
	{
		((BoolVal*)mValue)->setValue((bool)value->getValue());
	}
	else
	{
		// @TODO Erro fatal, atribuição com valor incorreto
		exit(1);
	}
}

void Symbol::setValue(FloatVal* value)
{
	if (mType == "int")
	{
		((IntVal*)mValue)->setValue((int)value->getValue());
	}
	else if (mType == "long")
	{
		((LongVal*)mValue)->setValue((long)value->getValue());
	}
	else if (mType == "double")
	{
		((DoubleVal*)mValue)->setValue((double)value->getValue());
	}
	else if (mType == "float")
	{
		((FloatVal*)mValue)->setValue(value->getValue());
	}
	else if (mType == "bool")
	{
		((BoolVal*)mValue)->setValue((bool)value->getValue());
	}
	else
	{
		// @TODO Erro fatal, atribuição com valor incorreto
		exit(1);
	}
}

void Symbol::setValue(DoubleVal* value)
{
	if (mType == "int")
	{
		((IntVal*)mValue)->setValue((int)value->getValue());
	}
	else if (mType == "long")
	{
		((LongVal*)mValue)->setValue((long)value->getValue());
	}
	else if (mType == "double")
	{
		((DoubleVal*)mValue)->setValue(value->getValue());
	}
	else if (mType == "float")
	{
		((FloatVal*)mValue)->setValue((float)value->getValue());
	}
	else if (mType == "bool")
	{
		((BoolVal*)mValue)->setValue((bool)value->getValue());
	}
	else
	{
		// @TODO Erro fatal, atribuição com valor incorreto
		exit(1);
	}
}

void Symbol::setValue(BoolVal* value)
{
	if (mType == "int")
	{
		((IntVal*)mValue)->setValue((int)value->getValue());
	}
	else if (mType == "long")
	{
		((LongVal*)mValue)->setValue((long)value->getValue());
	}
	else if (mType == "double")
	{
		((DoubleVal*)mValue)->setValue((double)value->getValue());
	}
	else if (mType == "float")
	{
		((FloatVal*)mValue)->setValue((float)value->getValue());
	}
	else if (mType == "bool")
	{
		((BoolVal*)mValue)->setValue(value->getValue());
	}
	else
	{
		// @TODO Erro fatal, atribuição com valor incorreto
		exit(1);
	}
}

void Symbol::setValue(StringVal* value)
{
	std::string str = value->getValue();
	if (mType == "int")
	{
		((IntVal*)mValue)->setValue(std::atoi(str.c_str()));
	}
	else if (mType == "long")
	{
		((LongVal*)mValue)->setValue((long)std::atoi(str.c_str()));
	}
	else if (mType == "double")
	{
		((DoubleVal*)mValue)->setValue((double)std::atof(str.c_str()));
	}
	else if (mType == "float")
	{
		((FloatVal*)mValue)->setValue((float)std::atof(str.c_str()));
	}
	else if (mType == "bool")
	{
		((BoolVal*)mValue)->setValue((bool)std::atoi(str.c_str()));
	}
	else
	{
		// @TODO Erro fatal, atribuição com valor incorreto
		exit(1);
	}
}

void Symbol::setValue(ObjectVal* value)
{
	if (mType == "object")
	{
		((ObjectVal*)mValue)->setValue(value->getValue());
	}
	else
	{
		// @TODO Erro fatal, atribuição com valor incorreto
		exit(1);
	}
}

void Symbol::setValue(std::string fromType, Val* value)
{
	if (fromType == "int")
	{
		setValue((IntVal*)value);
	}
	else if (fromType == "long")
	{
		setValue((LongVal*)value);
	}
	else if (fromType == "float")
	{
		setValue((FloatVal*)value);
	}
	else if (fromType == "double")
	{
		setValue((DoubleVal*)value);
	}
	else if (fromType == "bool")
	{
		setValue((BoolVal*)value);
	}
	else if (fromType == "string")
	{
		setValue((StringVal*)value);
	}
	else if (fromType == "object")
	{
		setValue((ObjectVal*)value);
	}
}
