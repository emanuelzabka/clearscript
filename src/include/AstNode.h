#pragma once

#include "ExprResult.h"

class AstNode {
	public:
		virtual ExprResult eval() = 0;
};

