#pragma once

#include <vector>
#include "AstNode.h"

enum BuiltinFunction {
	BF_PRINT,
	BF_SUBSTRING,
	BF_EXIT,
	BF_TOSTRING,
	BF_TONUMBER
};

class BuiltinFunCallNode: public AstNode {
	protected:
		BuiltinFunction mType;
		std::vector<AstNode*> mArgs;
		void evalPrint(ExprResult& res);
		/*
		void evalSubstring(ExprResult& res);
		void evalExit(ExprResult& res);
		void evalToString(ExprResult& res);
		void evalToNumber(ExprResult& res);
		*/
	public:
		BuiltinFunCallNode(BuiltinFunction type, std::vector<AstNode*> args);
		ExprResult eval();
};

