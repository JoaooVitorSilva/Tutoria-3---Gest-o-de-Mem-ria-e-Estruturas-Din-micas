# Tutoria 3 — Gestão de Memória e Estruturas Dinâmicas

**Disciplina:** Estruturas de Dados  
**Instituição:** UniSENAI  
**Contexto:** Domínio do Heap, Tipos Heterogêneos e Introdução à Arquitetura de TADs  

---

## Objetivo

Desenvolver as capacidades técnicas de implementar e manipular estruturas de dados de forma otimizada, garantindo a eficiência no uso da memória RAM e a proteção de dados através da modularização.

---

## Como compilar e executar

Todos os exercícios usam o compilador GCC. Exemplo geral:

```bash
gcc Exercicio_XX/exercicio_XX.c -o exercicio_XX
./exercicio_XX
```

> **Exercícios 19 e 20** possuem múltiplos arquivos (TAD). Compile assim:
> ```bash
> gcc Exercicio_19/main.c Exercicio_19/ponto.c -o ponto -lm
> ./ponto
> ```

---

## Estrutura de Pastas

```
tutoria3/
├── Exercicio_01/   exercicio_01.c
├── Exercicio_02/   exercicio_02.c
├── ...
├── Exercicio_19/   ponto.h  ponto.c  main.c
└── Exercicio_20/   ponto.h  ponto.c  main.c
```

---

## Lista de Exercícios

### Parte 1 — Fundamentos e Tipos Simples

#### Exercício 01 — Alocação Simples
Declare um ponteiro para `float`, aloque memória dinamicamente com `malloc`, receba um valor via teclado e exiba-o com duas casas decimais.

```bash
gcc Exercicio_01/exercicio_01.c -o ex01 && ./ex01
```

---

#### Exercício 02 — Gestão Segura
Tenta alocar 1 GB de memória. Verifica se o ponteiro é `NULL`, exibe mensagem de erro caso falhe e, se tiver sucesso, libera a memória imediatamente.

```bash
gcc Exercicio_02/exercicio_02.c -o ex02 && ./ex02
```

---

#### Exercício 03 — Vetores Dinâmicos
Pede ao usuário um tamanho N, aloca um vetor de inteiros, preenche-o e calcula a média aritmética. Usa `sizeof(int)` para garantir portabilidade.

```bash
gcc Exercicio_03/exercicio_03.c -o ex03 && ./ex03
```

---

#### Exercício 04 — Aritmética de Ponteiros
Aloca um vetor de 5 posições e percorre-o para impressão utilizando apenas o incremento de endereço (`ptr++`) e a indireção (`*`), sem usar colchetes `[]`.

```bash
gcc Exercicio_04/exercicio_04.c -o ex04 && ./ex04
```

---

#### Exercício 05 — Passagem por Referência
Cria uma função `void dobrar(int *num)` que recebe o endereço de um `int` e dobra seu valor original no `main`, utilizando ponteiros.

```bash
gcc Exercicio_05/exercicio_05.c -o ex05 && ./ex05
```

---

### Parte 2 — Tipos Heterogêneos (Structs)

#### Exercício 06 — Entidade Produto
Define uma `struct Produto` (ID e Preço). Aloca-a dinamicamente e atribui valores utilizando exclusivamente o operador seta (`->`).

```bash
gcc Exercicio_06/exercicio_06.c -o ex06 && ./ex06
```

---

#### Exercício 07 — Vetor de Registros
Utiliza `malloc` para criar um array dinâmico de 3 estruturas do tipo `Aluno` (nome e nota).

```bash
gcc Exercicio_07/exercicio_07.c -o ex07 && ./ex07
```

---

#### Exercício 08 — Reset de Dados
Implementa a função `void reset_estoque(Produto *p)` que zera os campos de uma struct passada por parâmetro.

```bash
gcc Exercicio_08/exercicio_08.c -o ex08 && ./ex08
```

---

#### Exercício 09 — Strings Dinâmicas
Cria uma `struct Usuario` com `char *nome`. Aloca a struct e depois aloca o espaço exato para o nome lido do teclado usando `strlen`.

```bash
gcc Exercicio_09/exercicio_09.c -o ex09 && ./ex09
```

---

#### Exercício 10 — Composição Dinâmica
Define `struct Endereco` e `struct Pessoa` com ponteiro para `Endereco`. Ambos alocados separadamente no Heap e conectados.

```bash
gcc Exercicio_10/exercicio_10.c -o ex10 && ./ex10
```

---

### Parte 3 — Avançado e Estruturas Especiais

#### Exercício 11 — Redimensionamento
Aloca vetor para 2 inteiros. Usa `realloc` para expandir para 4 inteiros conforme o usuário insere novos dados. Utiliza ponteiro temporário para verificar `NULL` antes de reassinalar.

```bash
gcc Exercicio_11/exercicio_11.c -o ex11 && ./ex11
```

---

#### Exercício 12 — Matriz Dinâmica
Aloca uma matriz M×N de inteiros usando ponteiro de ponteiros (`int **matriz`). Cada linha é alocada individualmente.

```bash
gcc Exercicio_12/exercicio_12.c -o ex12 && ./ex12
```

---

#### Exercício 13 — Liberação Profunda
Função `liberar_matriz(int **matriz, int m)` que libera cada linha antes do ponteiro principal, evitando vazamento de memória.

```bash
gcc Exercicio_13/exercicio_13.c -o ex13 && ./ex13
```

---

#### Exercício 14 — Vetor de Strings
Aloca um vetor de ponteiros para `char` para armazenar uma lista de nomes de cidades informada pelo usuário, com tamanho exato por `strlen`.

```bash
gcc Exercicio_14/exercicio_14.c -o ex14 && ./ex14
```

---

#### Exercício 15 — Clonagem
Função `Produto* clonar(Produto *origem)` que aloca um novo espaço e copia os dados de um produto existente.

```bash
gcc Exercicio_15/exercicio_15.c -o ex15 && ./ex15
```

---

#### Exercício 16 — Busca Sequencial
Em um vetor dinâmico de 10 produtos, função que busca um produto por ID e retorna seu endereço ou `NULL`.

```bash
gcc Exercicio_16/exercicio_16.c -o ex16 && ./ex16
```

---

#### Exercício 17 — Filtragem
Dado um vetor de alunos, gera um novo vetor dinâmico contendo apenas os endereços dos alunos aprovados (nota > 7.0).

```bash
gcc Exercicio_17/exercicio_17.c -o ex17 && ./ex17
```

---

#### Exercício 18 — Análise Big O
Percorre uma matriz N×N e identifica, em comentário no código, por que sua complexidade de tempo é O(n²).

```bash
gcc Exercicio_18/exercicio_18.c -o ex18 && ./ex18
```

---

#### Exercício 19 — TAD Geométrico (.h)
Arquivo `ponto.h` definindo a estrutura opaca `Ponto` e as assinaturas das funções `ponto_criar`, `ponto_distancia` e `ponto_destruir`.

---

#### Exercício 20 — TAD Geométrico (.c)
Arquivo `ponto.c` implementando o TAD com alocações no heap e cálculo de distância euclidiana via `sqrt` (`math.h`).

```bash
gcc Exercicio_20/main.c Exercicio_20/ponto.c -o ex20 -lm && ./ex20
```

---

## Boas Práticas Adotadas

- ✅ Verificação de `NULL` após todo `malloc` e `realloc`
- ✅ `free()` para toda memória alocada
- ✅ Ponteiros zerados com `= NULL` após `free`
- ✅ Comentários explicando a lógica de cada alocação
- ✅ Uso de `sizeof` para garantir portabilidade
- ✅ Ponteiro temporário no `realloc` para evitar vazamento em caso de falha
