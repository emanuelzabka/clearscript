#pragma once

#include "ExprVal.h"

template <class T>
void ExprVal<T>::setValue(T value)
{
	mValue = value;
}

template <class T>
T ExprVal<T>::getValue()
{
	return mValue;
}
