#pragma once

#include "ExprResult.h"

/**
 * Classe abstrata base para os nós da linguagem
 * Todos os nós da linguagem, que recebem significado na gramática, herdam deste
 */
class AstNode {
	public:
		/** Método que possui a inteligência de avaliar ou executar o nó atual */
		virtual ExprResult eval() = 0;
};

