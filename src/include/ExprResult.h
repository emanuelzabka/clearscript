#pragma once

#include <string>
#include "ExprVal.h"

class ExprResult {
	protected:
		std::string mType;
		Val* mValue;

	public:
		ExprResult();
		ExprResult(std::string type, Val* value);
		std::string getType();
		void setType(std::string type);
		void setValue(Val* value);
		void setValue(std::string type, long value);
		void setValue(std::string type, double value);
		Val* getValue();
		bool isNumeric();
		bool isFloat();
		bool isInteger();
		long getIntegerValue();
		double getFloatValue();
		bool getBoolVal();
		std::string getLargerType(ExprResult& res1, ExprResult& res2);
};

