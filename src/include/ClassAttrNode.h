#pragma once

#include "AstNode.h"
#include "ClassNode.h"

// Modificadores de visibilidade
enum VisModifier {
	VM_PUBLIC,
	VM_PROTECTED
};

class ClassAttrNode: public AstNode {
	protected:
		ClassNode* mParent;
		std::string mName;
		std::string mType;
		VisModifier mVisibility;
	public:
		ClassAttrNode(
			ClassNode* parent,
			std::string name,
			std::string type,
			VisModifier visibility
		);
};

