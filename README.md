clearscript
===========

Trabalho de faculdade para disciplina de Linguagens de programação.

Foram utilizadas as ferramentas flex e bison para realizar a identificação dos
tokens e gramática.

Aspectos implementados:
-----------------------

- Declaração de variáveis
- Declaração de funções
- Parâmetros de funções
- Chamada de funções
- Tipos primitivos: int, long, float, double e string.
- Recursão
- Declaração de ponto de entrada (função main)
- Operador de atribuição: =
- Operadores matemáticos +,-,/,%,\*
- Operador de concatenação de string ++
- Operadores lógicos: &&, ||, !
- Estruturas de controle: if-else
- Estruturas de repetição: while
- Funções built-in: print

Aspectos planejados porém não implementados:
--------------------------------------------

- Declaração de classes
- Declaração de atributos
- Declaração de métodos
- Tipos vetores
- Operadores de acesso à vetores
- Funções builtin: exit, substring, tostring, tonumber

Implementações deficientes:
---------------------------

- Gerenciamento de memória: praticamente nenhum cuidado foi tomado com o
  gerenciamento de memória. Problema principalmente com os valores (valores que
  herdam de ExprVal), são alocados em casts e resultados de expressões e nunca
  mais são desalocados. Pensou-se em usar alguma estratégia com smartpointers
  para resolver o problema.
- Retornos de função não tem seu tipo checkado ou coerente com a
  definição/declaração.
- Retorno de função (return) não desvia o fluxo de execução, apenas marcam o
  resultado.
- Acesso e busca na tabela de símbolos poderia ser muito otimizado.
- Condições de casts que baixam muito a eficiência da execução poderiam ser
  elimidados usando-se as informações de tipos já presentes nas expressões para
  saber o tipo final antes da execução de fato.

