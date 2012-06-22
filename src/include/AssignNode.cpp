#include <string>
#include "Log.h"
#include "AssignNode.h"

AssignNode::AssignNode(IdentifierNode* target, AstNode* value)
{
	mTarget = target;
	mValue = value;
}

ExprResult AssignNode::eval()
{
	ExprResult result;
	Symbol* sym = mTarget->getSymbol();
	if (sym != NULL)
	{
		ExprResult value = mValue->eval();
		sym->setValue(value.getType(), value.getValue());
		result.setValue(sym->getValue());
		result.setType(sym->getType());
	}
	else
	{
		std::string error = "Identificador <" + mTarget->getName() + "> não definido";
		Log::fatal(error);
	}
	return result;
}

