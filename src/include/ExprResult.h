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
		Val* getValue();
		bool isNumeric(ExprResult& res);
		bool isFloat(ExprResult& res);
		bool isInteger(ExprResult& res);
		long getIntegerValue(ExprResult& res);
		double getFloatValue(ExprResult& res);
};

