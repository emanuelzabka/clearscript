#pragma once

#include <string>
#include "AstNode.h"

class ClassNode: public AstNode {
	protected:
		std::string mName;
		AstNode* mBody;
	public:
		ClassNode(std::string name, AstNode* body);
		std::string getName();
};

