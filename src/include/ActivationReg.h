#pragma once

#include <vector>
#include <string>
#include "SymbolTable.h"

/**
 * Classe que gerencia a inserção e remoção de tabelas de símbolos de escopo
 * para funções. Escopos, aqui como tabelas de símbolos, podem ser empilhados e
 * desempilhados. A tabela de símbolos da base é considerada a tabela de símbolos
 * global do programa.
 */
class ActivationReg {
	protected:
		std::vector<SymbolTable*> mTables;
		static ActivationReg* mInstance;
		ActivationReg();
		~ActivationReg();
	public:
		/** Retorna a instância do gerenciador de registros de ativação */
		static ActivationReg* getInstance();
		/** Empilha uma tabela de símbolos */
		void push(SymbolTable* table);
		/** Remove a tabela de símbolos do topo da pilha */
		void pop();
		/** Retorna a tabela de símbolos corrente no topo */
		SymbolTable* top();
		/** Retorna a tabela de símbolos global (base) */
		SymbolTable* global();
		/** Retorna um tipo definido pelo programador */
		Symbol* getUserType(std::string type);
		/** Verifica se o tipo informado é um tipo primitivo da linguagem */
		bool isBuiltinType(std::string type);
};

