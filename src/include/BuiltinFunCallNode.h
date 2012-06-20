#pragma once

#include <vector>
#include "AstNode.h"

enum BuiltinFunction {
	BF_PRINT
};

class BuiltinFunCallNode: public AstNode {
	protected:
		BuiltinFunction mType;
		std::vector<AstNode*> mArgs;
		void evalPrint(ExprResult& res);
	public:
		BuiltinFunCallNode(BuiltinFunction type, std::vector<AstNode*> args);
		ExprResult eval();
};

