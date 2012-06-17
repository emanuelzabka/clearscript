#pragma once

#include <vector>
#include <string>
#include "AstNode.h"
#include "ClassNode.h"
#include "FuncArgNode.h"

class ClassMethodNode: public AstNode {
	protected:
		ClassNode* mParent;
		std::string mName;
		std::vector<FuncArgNode*> mArgs;
		AstNode* mBody;
	public:
		ClassMethodNode(
			ClassNode* parent,
			std::string name,
			std::vector<FuncArgNode*> args,
			AstNode* body
		);
};

