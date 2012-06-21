#include "ArgList.h"

ArgList::ArgList(AstNode* value, ArgList* next)
{
	mValue = value;
	mNext = next;
}

std::vector<AstNode*> ArgList::get()
{
	std::vector<AstNode*> result;
	result.push_back(mValue);
	if (mNext != NULL) {
		std::vector<AstNode*> values = mNext->get();
		for (int i = 0; i < values.size(); i++)
		{
			result.push_back(values[i]);
		}
	}
	return result;
}
