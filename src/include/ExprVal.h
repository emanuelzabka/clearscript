#pragma once

#include "Val.h"

/**
 * Classe Template para valores da linguagem
 */
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

