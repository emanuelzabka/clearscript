#pragma once

#include <string>
#include "AstNode.h"
#include "Val.h"
#include "IntVal.h"
#include "LongVal.h"
#include "FloatVal.h"
#include "DoubleVal.h"
#include "BoolVal.h"
#include "StringVal.h"
#include "ObjectVal.h"

class Symbol {
	protected:
		std::string mName;
		std::string mType;
		Val* mValue;
		bool mVar;
		void createValue();
		AstNode* mNode;

	public:
		Symbol(std::string name, std::string type);
		Symbol(std::string name, std::string type, bool var);
		std::string getName();
		std::string getType();
		void setType(std::string type);
		void setNode(AstNode* node);
		Val* getValue();
		void setValue(Val* value);
		void setValue(IntVal* value);
		void setValue(LongVal* value);
		void setValue(FloatVal* value);
		void setValue(DoubleVal* value);
		void setValue(BoolVal* value);
		void setValue(StringVal* value);
		void setValue(ObjectVal* value);
		void setValue(std::string fromType, Val* value);
		bool isVar();
};

