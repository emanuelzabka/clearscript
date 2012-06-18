#pragma once

#include "Val.h"

template <class T>
class ExprVal: public Val {
	protected:
		T mValue;
	public:
		void setValue(T value)
		{
			mValue = value;
		}

		T getValue()
		{
			return mValue;
		}
};

