## Analise-performance-algoritmos-ordenacao
Sistema em C para comparação de algoritmos de ordenação utilizando dados de queimadas do INPE

## Objetivo
Desenvolver um sistema capaz de analisar e comparar o desempenho de diferentes algoritmos de ordenação aplicados a dados de queimadas obtidos do INPE.

## Como utilizar
### Método 1 - Utilizando o Executável
1. Baixe os seguintes repositórios: [Executável](APS.exe) | [Banco de dados mg 2023](focos_br_mg_ref_2023.csv) | [Banco de dados mg 2024](focos_br_mg_ref_2024.csv)
2. Escolha o método de ordenação.
3. Aguarde o processamento e visualize os resultados.

### Método 2 - Compilando o Código Fonte

#### Pré-requisitos

- GCC ou MinGW instalado
- Visual Studio Code ou Dev-C++

#### Compilação

```bash
gcc *.c -o sistema
```

#### Execução

```bash
sistema.exe
```

---


## Algoritmos Implementados
- Bubble Sort
- Selection Sort
- Insertion Sort
- Quick Sort
- Merge Sort
- Heap Sort
- Shell Sort
- Cocktail Shaker Sort


## Complexidade dos Algoritmos
| Algoritmo | Complexidade Média |
|------------|------------------|
| Bubble Sort | O(n²) |
| Selection Sort | O(n²) |
| Insertion Sort | O(n²) |
| Cocktail Shaker Sort | O(n²) |
| Shell Sort | O(n^(3/2)) |
| Quick Sort | O(n log n) |
| Merge Sort | O(n log n) |
| Heap Sort | O(n log n) |


## Relatório
O relatório técnico detalha o desenvolvimento do sistema, incluindo:

- Fundamentação teórica sobre algoritmos de ordenação;
- Implementação em linguagem C;
- Estrutura do programa;
- Base de dados de queimadas do INPE;
- Metodologia de testes e validação;
- Comparação de desempenho entre os algoritmos implementados.

📄 Arquivo: [Visualizar Relatório](https://github.com/mariaair4m/analise-performance-algoritmos-ordenacao/blob/main/Relat%C3%B3rio_de_desenvolvimento.pdf)

## 🎓 Projeto Acadêmico

Projeto desenvolvido para estudo e comparação de desempenho entre diferentes algoritmos de ordenação aplicados a grandes volumes de dados reais.
