#pragma once

#include <vector>
#include "AstNode.h"

class ArgList {
	protected:
		AstNode* mValue;
		ArgList* mNext;
	public:
		ArgList(AstNode* value, ArgList* next);
		std::vector<AstNode*> get();
};

