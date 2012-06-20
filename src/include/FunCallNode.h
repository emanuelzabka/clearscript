#include <string>
#include <vector>
#include "AstNode.h"

class FunCallNode: public AstNode {
	protected:
		std::string mName;
		std::vector<AstNode*> mArgs;
	public:
		FunCallNode(std::string name, std::vector<AstNode*> args);
		ExprResult eval();
};

