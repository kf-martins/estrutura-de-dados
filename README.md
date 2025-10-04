# Estrutura de Dados

Este repositório é dedicado às aulas e implementações da disciplina de Estrutura de Dados I do curso de Ciência de Dados e Inteligência Artificial da UEL (Universidade Estadual de Londrina).

- Nome: Kauã Felipe Martins
- Professor: Andre Luis Andrade Menolli
- Universidade Estadual de Londrina (UEL)
- Curso: Ciência de Dados e Inteligência Artificial


## Sobre a disciplina

A disciplina de Estrutura de Dados I tem como objetivo apresentar os principais tipos abstratos de dados e suas implementações, análise de complexidade e estruturas fundamentais. Entre os tópicos comuns estão:

- Vetores e arrays
- Listas simplesmente/duplamente encadeadas
- Pilhas (stacks) e filas (queues)
- Árvores básicas (introdução)
- Análise de complexidade (tempo e espaço)

As implementações deste repositório foram desenvolvidos em C e C++. Ao longo dos exercícios você verá arquivos `.c`, `.h`, `.cpp` e `.hpp` organizados por tema.


## Como compilar e executar (C / C++)

Recomenda-se ter instalados `gcc` e `g++`. Exemplos básicos:

Compilar um arquivo C único:

```bash
gcc -std=c11 -O2 -Wall -Wextra -o programa arquivo.c
```

Compilar um arquivo C++ único:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -o programa arquivo.cpp
```

Compilar e executar no diretório `Filas` (exemplo usando `ex123.c`):

```bash
cd Filas
gcc -std=c11 -O2 -Wall -Wextra ex123.c -o ex123
./ex123
```

Para compilar todos os arquivos C em um diretório (exemplo):

```bash
gcc -std=c11 -O2 -Wall -Wextra *.c -o todos_exemplos
```
