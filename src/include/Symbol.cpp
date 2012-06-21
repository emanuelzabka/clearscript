#include <cstdlib>
#include "Symbol.h"
#include "Log.h"

#include <stdio.h>

Symbol::Symbol(std::string name, std::string type)
{
	mName = name;
	mType = type;
	mValue = NULL;
	mNode = NULL;
	mVar = false;
}

Symbol::~Symbol()
{
	if (mValue != NULL)
	{
		delete mValue;
	}
}

Symbol::Symbol(std::string name, std::string type, bool var)
{
	mName = name;
	mType = type;
	mNode = NULL;
	mVar = var;
	if (mVar)
	{
		createValue();
	}
}

void Symbol::createValue()
{
	if (mType == "int")
	{
		mValue = (Val*)new IntVal(0);
	}
	else if (mType == "long")
	{
		mValue = (Val*)new LongVal(0);
	}
	else if (mType == "float")
	{
		mValue = (Val*)new FloatVal(0.0);
	}
	else if (mType == "double")
	{
		mValue = (Val*)new DoubleVal(0.0);
	}
	else if (mType == "bool")
	{
		mValue = (Val*)new BoolVal(false);
	}
	else if (mType == "string")
	{
		mValue = (Val*)new StringVal("");
	}
	else
	{
		// Object
		mValue = (Val*)new ObjectVal(NULL);
	}
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

void Symbol::setNode(AstNode* node)
{
	mNode = node;
}

AstNode* Symbol::getNode()
{
	return mNode;
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
		Log::fatal("Atribuição com tipo de valor incorreto");
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
		Log::fatal("Atribuição com tipo de valor incorreto");
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
		Log::fatal("Atribuição com tipo de valor incorreto");
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
		Log::fatal("Atribuição com tipo de valor incorreto");
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
		Log::fatal("Atribuição com tipo de valor incorreto");
	}
}

void Symbol::setValue(StringVal* value)
{
	std::string str = value->getValue();
	if (mType == "string")
	{
		((StringVal*)mValue)->setValue(str);
	}
	else if (mType == "int")
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
		Log::fatal("Atribuição com tipo de valor incorreto");
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
		Log::fatal("Atribuição com tipo de valor incorreto");
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
		// @TODO Verificar o tipo do objeto nesse caso
		setValue((ObjectVal*)value);
	}
}
