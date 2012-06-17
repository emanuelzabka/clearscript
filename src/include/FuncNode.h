#pragma once

#include <string>
#include <vector>
#include "AstNode.h"
#include "FuncArgNode.h"

class FuncNode: public AstNode {
	protected:
		std::string mName;
		std::vector<FuncArgNode*> mArgs;
		AstNode* mBody;
	public:
		FuncNode(std::string name, std::vector<FuncArgNode*> args, AstNode* body);
};

