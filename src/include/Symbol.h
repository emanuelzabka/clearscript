#pragma once

#include <string>
#include "AstNode.h"
#include "Val.h"
#include "IntVal.h"
#include "LongVal.h"
#include "FloatVal.h"
#include "DoubleVal.h"
#include "BoolVal.h"
#include "StringVal.h"
#include "ObjectVal.h"

/**
 * Classe que gerencia uma entrada na tabela de símbolos
 */
class Symbol {
	protected:
		/** Nome do símbolo */
		std::string mName;
		/** Tipo do símbolo, atualmente, tipo primitivo ou function */
		std::string mType;
		/** Valor guardado pelo símbolo */
		Val* mValue;
		/** Indica se o símbolo é uma variável */
		bool mVar;
		/** Cria o valor respectivo do símbolo conforme seu tipo */
		void createValue();
		/** Nó correspondente à implementação do símbolo, utilizado para guardar
		o corpo de funções, métodos ou classes */
		AstNode* mNode;
	public:
		Symbol(std::string name, std::string type);
		Symbol(std::string name, std::string type, bool var);
		~Symbol();
		std::string getName();
		std::string getType();
		void setType(std::string type);
		void setNode(AstNode* node);
		AstNode* getNode();
		Val* getValue();
		void setValue(Val* value);
		void setValue(IntVal* value);
		void setValue(LongVal* value);
		void setValue(FloatVal* value);
		void setValue(DoubleVal* value);
		void setValue(BoolVal* value);
		void setValue(StringVal* value);
		void setValue(ObjectVal* value);
		void setValue(std::string fromType, Val* value);
		bool isVar();
};

