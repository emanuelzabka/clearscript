#include "ArgDefList.h"

ArgDefList::ArgDefList(FuncArgNode* value, ArgDefList* next)
{
	mValue = value;
	mNext = next;
}

std::vector<FuncArgNode*> ArgDefList::get()
{
	std::vector<FuncArgNode*> result;
	result.push_back(mValue);
	if (mNext != NULL) {
		std::vector<FuncArgNode*> values = mNext->get();
		for (int i = 0; i < values.size(); i++)
		{
			result.push_back(values[i]);
		}
	}
	return result;
}
