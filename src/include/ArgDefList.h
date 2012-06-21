#pragma once

#include <vector>
#include "FuncArgNode.h"

class ArgDefList {
	protected:
		FuncArgNode* mValue;
		ArgDefList* mNext;
	public:
		ArgDefList(FuncArgNode* value, ArgDefList* next);
		std::vector<FuncArgNode*> get();
};

