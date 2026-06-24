#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


long long dataParaNumero(const char* data) {
    char buffer[15];
    int k = 0;
    int i;
	for (i = 0; data[i] != '\0' && k < 14; i++) {
        if (isdigit((unsigned char)data[i])) buffer[k++] = data[i];
    }
    buffer[k] = '\0';
    return atoll(buffer);
}

void trocaLinha(char** linhas, int i, int j) {
    char* temp = linhas[i];
    linhas[i] = linhas[j];
    linhas[j] = temp;
}

// --- Selection Sort ---
int SelectionSort(char** linhas, void* coluna, int tipo, int n) {
    int trocas = 0;
    int i,j;
    for (i = 0; i < n; i++) {
        int min = i;
        for (j = i + 1; j < n; j++) {
            bool menor = false;
            if (tipo == 0 && ((int*)coluna)[j] < ((int*)coluna)[min]) menor = true;
            if (tipo == 1 && ((float*)coluna)[j] < ((float*)coluna)[min]) menor = true;
            if (tipo == 2 && strcmp(((char**)coluna)[j], ((char**)coluna)[min]) < 0) menor = true;
            if (tipo == 3 && ((long long*)coluna)[j] < ((long long*)coluna)[min]) menor = true;
            if (menor) min = j;
        }
        if (min != i) {
            if (tipo == 0) { int t = ((int*)coluna)[i]; ((int*)coluna)[i] = ((int*)coluna)[min]; ((int*)coluna)[min] = t; }
            if (tipo == 1) { float t = ((float*)coluna)[i]; ((float*)coluna)[i] = ((float*)coluna)[min]; ((float*)coluna)[min] = t; }
            if (tipo == 2) { char* t = ((char**)coluna)[i]; ((char**)coluna)[i] = ((char**)coluna)[min]; ((char**)coluna)[min] = t; }
            if (tipo == 3) { long long t = ((long long*)coluna)[i]; ((long long*)coluna)[i] = ((long long*)coluna)[min]; ((long long*)coluna)[min] = t; }
            trocaLinha(linhas, i, min);
            trocas++;
        }
    }
    return trocas;
}
// --- Bubble Sort ---
int BubbleSort(char** linhas, void* coluna, int tipo, int n) {
    int trocas = 0;
    bool troca = true;
    while (troca) {
    	int i;
        troca = false;
        for (i = 0; i < n - 1; i++) {
            bool precisa = false;
            if (tipo == 0 && ((int*)coluna)[i] > ((int*)coluna)[i + 1]) precisa = true;
            if (tipo == 1 && ((float*)coluna)[i] > ((float*)coluna)[i + 1]) precisa = true;
            if (tipo == 2 && strcmp(((char**)coluna)[i], ((char**)coluna)[i + 1]) > 0) precisa = true;
            if (tipo == 3 && ((long long*)coluna)[i] > ((long long*)coluna)[i + 1]) precisa = true;
            if (precisa) {
                if (tipo == 0) { int t = ((int*)coluna)[i]; ((int*)coluna)[i] = ((int*)coluna)[i + 1]; ((int*)coluna)[i + 1] = t; }
                if (tipo == 1) { float t = ((float*)coluna)[i]; ((float*)coluna)[i] = ((float*)coluna)[i + 1]; ((float*)coluna)[i + 1] = t; }
                if (tipo == 2) { char* t = ((char**)coluna)[i]; ((char**)coluna)[i] = ((char**)coluna)[i + 1]; ((char**)coluna)[i + 1] = t; }
                if (tipo == 3) { long long t = ((long long*)coluna)[i]; ((long long*)coluna)[i] = ((long long*)coluna)[i + 1]; ((long long*)coluna)[i + 1] = t; }
                trocaLinha(linhas, i, i + 1);
                troca = true;
                trocas++;
            }
        }
    }
    return trocas;
}

// --- Insertion Sort ---
int InsertionSort(char** linhas, void* coluna, int tipo, int n) {
    int trocas = 0;
    int i;
    for (i = 1; i < n; i++) {
        int j = i - 1;
        char* linhaChave = linhas[i];
        if (tipo == 0) {
            int chave = ((int*)coluna)[i];
            while (j >= 0 && ((int*)coluna)[j] > chave) {
                ((int*)coluna)[j + 1] = ((int*)coluna)[j];
                linhas[j + 1] = linhas[j];
                j--;
                trocas++;
            }
            ((int*)coluna)[j + 1] = chave;
        } else if (tipo == 1) {
            float chave = ((float*)coluna)[i];
            while (j >= 0 && ((float*)coluna)[j] > chave) {
                ((float*)coluna)[j + 1] = ((float*)coluna)[j];
                linhas[j + 1] = linhas[j];
                j--;
                trocas++;
            }
            ((float*)coluna)[j + 1] = chave;
        } else if (tipo == 2) {
            char* chave = ((char**)coluna)[i];
            while (j >= 0 && strcmp(((char**)coluna)[j], chave) > 0) {
                ((char**)coluna)[j + 1] = ((char**)coluna)[j];
                linhas[j + 1] = linhas[j];
                j--;
                trocas++;
            }
            ((char**)coluna)[j + 1] = chave;
        } else if (tipo == 3) {
            long long chave = ((long long*)coluna)[i];
            while (j >= 0 && ((long long*)coluna)[j] > chave) {
                ((long long*)coluna)[j + 1] = ((long long*)coluna)[j];
                linhas[j + 1] = linhas[j];
                j--;
                trocas++;
            }
            ((long long*)coluna)[j + 1] = chave;
        }
        linhas[j + 1] = linhaChave;
    }
    return trocas;
}
// --- Cocktail Shaker Sort ---
int CocktailShakerSort(char** linhas, void* coluna, int tipo, int n) {
    int trocas = 0;
    bool troca = true;
    int inicio = 0, fim = n - 1;
    while (troca) {
    	int i;
        troca = false;
        for (i = inicio; i < fim; i++) {
            bool precisa = false;
            if (tipo == 0 && ((int*)coluna)[i] > ((int*)coluna)[i + 1]) precisa = true;
            if (tipo == 1 && ((float*)coluna)[i] > ((float*)coluna)[i + 1]) precisa = true;
            if (tipo == 2 && strcmp(((char**)coluna)[i], ((char**)coluna)[i + 1]) > 0) precisa = true;
            if (tipo == 3 && ((long long*)coluna)[i] > ((long long*)coluna)[i + 1]) precisa = true;
            if (precisa) {
                if (tipo == 0) { int t = ((int*)coluna)[i]; ((int*)coluna)[i] = ((int*)coluna)[i + 1]; ((int*)coluna)[i + 1] = t; }
                if (tipo == 1) { float t = ((float*)coluna)[i]; ((float*)coluna)[i] = ((float*)coluna)[i + 1]; ((float*)coluna)[i + 1] = t; }
                if (tipo == 2) { char* t = ((char**)coluna)[i]; ((char**)coluna)[i] = ((char**)coluna)[i + 1]; ((char**)coluna)[i + 1] = t; }
                if (tipo == 3) { long long t = ((long long*)coluna)[i]; ((long long*)coluna)[i] = ((long long*)coluna)[i + 1]; ((long long*)coluna)[i + 1] = t; }
                trocaLinha(linhas, i, i + 1);
                troca = true;
                trocas++;
            }
        }
        if (!troca) break;
        troca = false;
        fim--;
        for (i = fim; i > inicio; i--) {
            bool precisa = false;
            if (tipo == 0 && ((int*)coluna)[i - 1] > ((int*)coluna)[i]) precisa = true;
            if (tipo == 1 && ((float*)coluna)[i - 1] > ((float*)coluna)[i]) precisa = true;
            if (tipo == 2 && strcmp(((char**)coluna)[i - 1], ((char**)coluna)[i]) > 0) precisa = true;
            if (tipo == 3 && ((long long*)coluna)[i - 1] > ((long long*)coluna)[i]) precisa = true;
            if (precisa) {
                if (tipo == 0) { int t = ((int*)coluna)[i - 1]; ((int*)coluna)[i - 1] = ((int*)coluna)[i]; ((int*)coluna)[i] = t; }
                if (tipo == 1) { float t = ((float*)coluna)[i - 1]; ((float*)coluna)[i - 1] = ((float*)coluna)[i]; ((float*)coluna)[i] = t; }
                if (tipo == 2) { char* t = ((char**)coluna)[i - 1]; ((char**)coluna)[i - 1] = ((char**)coluna)[i]; ((char**)coluna)[i] = t; }
                if (tipo == 3) { long long t = ((long long*)coluna)[i - 1]; ((long long*)coluna)[i - 1] = ((long long*)coluna)[i]; ((long long*)coluna)[i] = t; }
                trocaLinha(linhas, i - 1, i);
                troca = true;
                trocas++;
            }
        }
        inicio++;
    }
    return trocas;
}

// --- Quick Sort ---
int QuickSortRec(char** linhas, void* coluna, int tipo, int inicio, int fim) {
    int trocas = 0;

    if (inicio >= fim) return trocas;

    int pivoIndex = inicio;
    int i = inicio + 1;
    int j = fim;

    while (i <= j) {
        bool condicaoEsquerda = false;
        bool condicaoDireita = false;

        if (tipo == 0 && ((int*)coluna)[i] <= ((int*)coluna)[pivoIndex]) condicaoEsquerda = true;
        if (tipo == 1 && ((float*)coluna)[i] <= ((float*)coluna)[pivoIndex]) condicaoEsquerda = true;
        if (tipo == 2 && strcmp(((char**)coluna)[i], ((char**)coluna)[pivoIndex]) <= 0) condicaoEsquerda = true;
        if (tipo == 3 && ((long long*)coluna)[i] <= ((long long*)coluna)[pivoIndex]) condicaoEsquerda = true;

        if (tipo == 0 && ((int*)coluna)[j] > ((int*)coluna)[pivoIndex]) condicaoDireita = true;
        if (tipo == 1 && ((float*)coluna)[j] > ((float*)coluna)[pivoIndex]) condicaoDireita = true;
        if (tipo == 2 && strcmp(((char**)coluna)[j], ((char**)coluna)[pivoIndex]) > 0) condicaoDireita = true;
        if (tipo == 3 && ((long long*)coluna)[j] > ((long long*)coluna)[pivoIndex]) condicaoDireita = true;

        if (condicaoEsquerda) i++;
        else if (condicaoDireita) j--;
        else {
            if (tipo == 0) { int t = ((int*)coluna)[i]; ((int*)coluna)[i] = ((int*)coluna)[j]; ((int*)coluna)[j] = t; }
            if (tipo == 1) { float t = ((float*)coluna)[i]; ((float*)coluna)[i] = ((float*)coluna)[j]; ((float*)coluna)[j] = t; }
            if (tipo == 2) { char* t = ((char**)coluna)[i]; ((char**)coluna)[i] = ((char**)coluna)[j]; ((char**)coluna)[j] = t; }
            if (tipo == 3) { long long t = ((long long*)coluna)[i]; ((long long*)coluna)[i] = ((long long*)coluna)[j]; ((long long*)coluna)[j] = t; }

            trocaLinha(linhas, i, j);
            trocas++;
            i++;
            j--;
        }
    }

    if (tipo == 0) { int t = ((int*)coluna)[pivoIndex]; ((int*)coluna)[pivoIndex] = ((int*)coluna)[j]; ((int*)coluna)[j] = t; }
    if (tipo == 1) { float t = ((float*)coluna)[pivoIndex]; ((float*)coluna)[pivoIndex] = ((float*)coluna)[j]; ((float*)coluna)[j] = t; }
    if (tipo == 2) { char* t = ((char**)coluna)[pivoIndex]; ((char**)coluna)[pivoIndex] = ((char**)coluna)[j]; ((char**)coluna)[j] = t; }
    if (tipo == 3) { long long t = ((long long*)coluna)[pivoIndex]; ((long long*)coluna)[pivoIndex] = ((long long*)coluna)[j]; ((long long*)coluna)[j] = t; }

    trocaLinha(linhas, pivoIndex, j);
    trocas++;


    trocas += QuickSortRec(linhas, coluna, tipo, inicio, j - 1);
    trocas += QuickSortRec(linhas, coluna, tipo, j + 1, fim);

    return trocas;
}


int QuickSort(char** linhas, void* coluna, int tipo, int n) {
    return QuickSortRec(linhas, coluna, tipo, 0, n - 1);
}
// --- Merge Sort ---
void merge(char** linhas, void* coluna, int tipo, int esquerda, int meio, int direita, int* trocas) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    char** Llinhas = (char**)malloc(n1 * sizeof(char*));
    char** Rlinhas = (char**)malloc(n2 * sizeof(char*));

    void* Lcoluna;
    void* Rcoluna;

    if (tipo == 0) {
        Lcoluna = malloc(n1 * sizeof(int));
        Rcoluna = malloc(n2 * sizeof(int));
    } else if (tipo == 1) {
        Lcoluna = malloc(n1 * sizeof(float));
        Rcoluna = malloc(n2 * sizeof(float));
    } else if (tipo == 2) {
        Lcoluna = malloc(n1 * sizeof(char*));
        Rcoluna = malloc(n2 * sizeof(char*));
    } else {
        Lcoluna = malloc(n1 * sizeof(long long));
        Rcoluna = malloc(n2 * sizeof(long long));
    }

    for (i = 0; i < n1; i++) {
        Llinhas[i] = linhas[esquerda + i];
        if (tipo == 0) ((int*)Lcoluna)[i] = ((int*)coluna)[esquerda + i];
        if (tipo == 1) ((float*)Lcoluna)[i] = ((float*)coluna)[esquerda + i];
        if (tipo == 2) ((char**)Lcoluna)[i] = ((char**)coluna)[esquerda + i];
        if (tipo == 3) ((long long*)Lcoluna)[i] = ((long long*)coluna)[esquerda + i];
    }

    for (j = 0; j < n2; j++) {
        Rlinhas[j] = linhas[meio + 1 + j];
        if (tipo == 0) ((int*)Rcoluna)[j] = ((int*)coluna)[meio + 1 + j];
        if (tipo == 1) ((float*)Rcoluna)[j] = ((float*)coluna)[meio + 1 + j];
        if (tipo == 2) ((char**)Rcoluna)[j] = ((char**)coluna)[meio + 1 + j];
        if (tipo == 3) ((long long*)Rcoluna)[j] = ((long long*)coluna)[meio + 1 + j];
    }

    i = 0; j = 0; k = esquerda;

    while (i < n1 && j < n2) {
        bool menor = false;

        if (tipo == 0 && ((int*)Lcoluna)[i] <= ((int*)Rcoluna)[j]) menor = true;
        if (tipo == 1 && ((float*)Lcoluna)[i] <= ((float*)Rcoluna)[j]) menor = true;
        if (tipo == 2 && strcmp(((char**)Lcoluna)[i], ((char**)Rcoluna)[j]) <= 0) menor = true;
        if (tipo == 3 && ((long long*)Lcoluna)[i] <= ((long long*)Rcoluna)[j]) menor = true;

        if (menor) {
            linhas[k] = Llinhas[i];
            if (tipo == 0) ((int*)coluna)[k] = ((int*)Lcoluna)[i];
            if (tipo == 1) ((float*)coluna)[k] = ((float*)Lcoluna)[i];
            if (tipo == 2) ((char**)coluna)[k] = ((char**)Lcoluna)[i];
            if (tipo == 3) ((long long*)coluna)[k] = ((long long*)Lcoluna)[i];
            i++;
        } else {
            linhas[k] = Rlinhas[j];
            if (tipo == 0) ((int*)coluna)[k] = ((int*)Rcoluna)[j];
            if (tipo == 1) ((float*)coluna)[k] = ((float*)Rcoluna)[j];
            if (tipo == 2) ((char**)coluna)[k] = ((char**)Rcoluna)[j];
            if (tipo == 3) ((long long*)coluna)[k] = ((long long*)Rcoluna)[j];
            j++;
        }
        (*trocas)++; // ? conta a troca
        k++;
    }

    while (i < n1) {
        linhas[k] = Llinhas[i];
        if (tipo == 0) ((int*)coluna)[k] = ((int*)Lcoluna)[i];
        if (tipo == 1) ((float*)coluna)[k] = ((float*)Lcoluna)[i];
        if (tipo == 2) ((char**)coluna)[k] = ((char**)Lcoluna)[i];
        if (tipo == 3) ((long long*)coluna)[k] = ((long long*)Lcoluna)[i];
        i++;
        k++;
        (*trocas)++; // ? conta a troca
    }

    while (j < n2) {
        linhas[k] = Rlinhas[j];
        if (tipo == 0) ((int*)coluna)[k] = ((int*)Rcoluna)[j];
        if (tipo == 1) ((float*)coluna)[k] = ((float*)Rcoluna)[j];
        if (tipo == 2) ((char**)coluna)[k] = ((char**)Rcoluna)[j];
        if (tipo == 3) ((long long*)coluna)[k] = ((long long*)Rcoluna)[j];
        j++;
        k++;
        (*trocas)++; // ? conta a troca
    }

    free(Llinhas);
    free(Rlinhas);
    free(Lcoluna);
    free(Rcoluna);
}

void mergeSort(char** linhas, void* coluna, int tipo, int esquerda, int direita, int* trocas) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        mergeSort(linhas, coluna, tipo, esquerda, meio, trocas);
        mergeSort(linhas, coluna, tipo, meio + 1, direita, trocas);
        merge(linhas, coluna, tipo, esquerda, meio, direita, trocas);
    }
}

int MergeSort(char** linhas, void* coluna, int tipo, int n) {
    int trocas = 0;
    mergeSort(linhas, coluna, tipo, 0, n - 1, &trocas);
    return trocas; 
}



// --- Shell Sort ---
int ShellSort(char** linhas, void* coluna, int tipo, int n) {
    int trocas = 0;
    int i, j, gap;
    
    gap = n / 2;
    
    while (gap > 0) {
        for (i = gap; i < n; i++) {
            bool trocou = false;

            if (tipo == 0) {
                int temp = ((int*)coluna)[i];
                j = i;
                while (j >= gap && ((int*)coluna)[j - gap] > temp) {
                    ((int*)coluna)[j] = ((int*)coluna)[j - gap];
                    trocaLinha(linhas, j, j - gap);
                    j -= gap;
                    trocas++;
                    trocou = true;
                }
                ((int*)coluna)[j] = temp;
            }

            else if (tipo == 1) {
                float temp = ((float*)coluna)[i];
                j = i;
                while (j >= gap && ((float*)coluna)[j - gap] > temp) {
                    ((float*)coluna)[j] = ((float*)coluna)[j - gap];
                    trocaLinha(linhas, j, j - gap);
                    j -= gap;
                    trocas++;
                    trocou = true;
                }
                ((float*)coluna)[j] = temp;
            }

            else if (tipo == 2) {
                char* temp = ((char**)coluna)[i];
                j = i;
                while (j >= gap && strcmp(((char**)coluna)[j - gap], temp) > 0) {
                    ((char**)coluna)[j] = ((char**)coluna)[j - gap];
                    trocaLinha(linhas, j, j - gap);
                    j -= gap;
                    trocas++;
                    trocou = true;
                }
                ((char**)coluna)[j] = temp;
            }

            else if (tipo == 3) {
                long long temp = ((long long*)coluna)[i];
                j = i;
                while (j >= gap && ((long long*)coluna)[j - gap] > temp) {
                    ((long long*)coluna)[j] = ((long long*)coluna)[j - gap];
                    trocaLinha(linhas, j, j - gap);
                    j -= gap;
                    trocas++;
                    trocou = true;
                }
                ((long long*)coluna)[j] = temp;
            }
        }
        gap /= 2;
    }
    
    return trocas;
}



// --- Heap Sort ---
int heapify(char** linhas, void* coluna, int tipo, int n, int i) {
    int trocas = 0;
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (tipo == 0) {
        if (esq < n && ((int*)coluna)[esq] > ((int*)coluna)[maior]) maior = esq;
        if (dir < n && ((int*)coluna)[dir] > ((int*)coluna)[maior]) maior = dir;
        if (maior != i) {
            int t = ((int*)coluna)[i];
            ((int*)coluna)[i] = ((int*)coluna)[maior];
            ((int*)coluna)[maior] = t;
            trocaLinha(linhas, i, maior);
            trocas++;
            trocas += heapify(linhas, coluna, tipo, n, maior);
        }
    } else if (tipo == 1) {
        if (esq < n && ((float*)coluna)[esq] > ((float*)coluna)[maior]) maior = esq;
        if (dir < n && ((float*)coluna)[dir] > ((float*)coluna)[maior]) maior = dir;
        if (maior != i) {
            float t = ((float*)coluna)[i];
            ((float*)coluna)[i] = ((float*)coluna)[maior];
            ((float*)coluna)[maior] = t;
            trocaLinha(linhas, i, maior);
            trocas++;
            trocas += heapify(linhas, coluna, tipo, n, maior);
        }
    } else if (tipo == 2) {
        if (esq < n && strcmp(((char**)coluna)[esq], ((char**)coluna)[maior]) > 0) maior = esq;
        if (dir < n && strcmp(((char**)coluna)[dir], ((char**)coluna)[maior]) > 0) maior = dir;
        if (maior != i) {
            char* t = ((char**)coluna)[i];
            ((char**)coluna)[i] = ((char**)coluna)[maior];
            ((char**)coluna)[maior] = t;
            trocaLinha(linhas, i, maior);
            trocas++;
            trocas += heapify(linhas, coluna, tipo, n, maior);
        }
    } else if (tipo == 3) {
        if (esq < n && ((long long*)coluna)[esq] > ((long long*)coluna)[maior]) maior = esq;
        if (dir < n && ((long long*)coluna)[dir] > ((long long*)coluna)[maior]) maior = dir;
        if (maior != i) {
            long long t = ((long long*)coluna)[i];
            ((long long*)coluna)[i] = ((long long*)coluna)[maior];
            ((long long*)coluna)[maior] = t;
            trocaLinha(linhas, i, maior);
            trocas++;
            trocas += heapify(linhas, coluna, tipo, n, maior);
        }
    }
    return trocas;
}


int HeapSort(char** linhas, void* coluna, int tipo, int n) {
    int trocas = 0;
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        trocas += heapify(linhas, coluna, tipo, n, i);

    for (i = n - 1; i > 0; i--) {
        if (tipo == 0) { int t = ((int*)coluna)[0]; ((int*)coluna)[0] = ((int*)coluna)[i]; ((int*)coluna)[i] = t; }
        if (tipo == 1) { float t = ((float*)coluna)[0]; ((float*)coluna)[0] = ((float*)coluna)[i]; ((float*)coluna)[i] = t; }
        if (tipo == 2) { char* t = ((char**)coluna)[0]; ((char**)coluna)[0] = ((char**)coluna)[i]; ((char**)coluna)[i] = t; }
        if (tipo == 3) { long long t = ((long long*)coluna)[0]; ((long long*)coluna)[0] = ((long long*)coluna)[i]; ((long long*)coluna)[i] = t; }
        trocaLinha(linhas, 0, i);
        trocas++;
        trocas += heapify(linhas, coluna, tipo, i, 0);
    }
    return trocas;
}

int main(void) {
    int opcaoArquivo;
    printf("Escolha o conjunto de dados:\n");
    printf("1 - Dados de 2023\n");
    printf("2 - Dados de 2024\n");
    printf("Opcao: ");
    scanf("%d", &opcaoArquivo);

    const char* arquivo2023 = "focos_br_mg_ref_2023.csv";
    const char* arquivo2024 = "focos_br_mg_ref_2024.csv";

    FILE* arquivo1 = NULL;
    FILE* arquivo2 = NULL;

    switch (opcaoArquivo) {
        case 1:
            arquivo1 = fopen(arquivo2023, "r");
            if (!arquivo1) {
                perror("Erro ao abrir arquivo de 2023");
                return 1;
            }
            break;

        case 2:
            arquivo1 = fopen(arquivo2024, "r");
            if (!arquivo1) {
                perror("Erro ao abrir arquivo de 2024");
                return 1;
            }
            break;

        default:
            printf("Opcao invalida!\n");
            return 1;
    }

    char buffer[65536];
    char** linhas = NULL;
    int contador = 0;

    while (fgets(buffer, sizeof(buffer), arquivo1)) {
        buffer[strcspn(buffer, "\r\n")] = '\0';
        linhas = (char**)realloc(linhas, (contador + 1) * sizeof(char*));
        linhas[contador] = (char*)malloc(strlen(buffer) + 1);
        strcpy(linhas[contador], buffer);
        contador++;
    }
    fclose(arquivo1);

    
    if (arquivo2 != NULL) {
        while (fgets(buffer, sizeof(buffer), arquivo2)) {
            buffer[strcspn(buffer, "\r\n")] = '\0';
            linhas = (char**)realloc(linhas, (contador + 1) * sizeof(char*));
            linhas[contador] = (char*)malloc(strlen(buffer) + 1);
            strcpy(linhas[contador], buffer);
            contador++;
        }
        fclose(arquivo2);
    }

    const char* nomesColunas[] = {"id_bdq","foco_id","lat","lon","data_pas","pais","estado","municipio","bioma"};
    int tiposColunas[] = {-1, -1, 1, 1, 3, -1, -1, 2, 2};
    int numColunas = 9;

    int escolha;
    printf("Escolha o algoritmo de ordenacao:\n");
    printf("1 - Selection Sort\n");
    printf("2 - Bubble Sort\n");
    printf("3 - Insertion Sort\n");
    printf("4 - Cocktail Shaker Sort\n");
    printf("5 - Quick Sort\n");
    printf("6 - Merge Sort\n");
    printf("7 - Shell Sort\n");
    printf("8 - Heap Sort\n");
    printf("Opcao: ");
    scanf("%d", &escolha);

    char nomeEscolhido[100];
    printf("\nColunas ordenaveis: lat, lon, data_pas, municipio, bioma\n");
    printf("Digite o nome da coluna: ");
    scanf("%99s", nomeEscolhido);

    int indiceColuna = -1;
    int i;
    for (i = 0; i < numColunas; i++) {
        if (strcmp(nomeEscolhido, nomesColunas[i]) == 0) {
            indiceColuna = i;
            break;
        }
    }

    if (indiceColuna == -1 || tiposColunas[indiceColuna] == -1) {
        printf("Coluna invalida ou nao ordenavel!\n");
        return 1;
    }

    int tipoColuna = tiposColunas[indiceColuna];

    void* coluna = NULL;
    if (tipoColuna == 0) coluna = malloc(contador * sizeof(int));
    if (tipoColuna == 1) coluna = malloc(contador * sizeof(float));
    if (tipoColuna == 2) coluna = malloc(contador * sizeof(char*));
    if (tipoColuna == 3) coluna = malloc(contador * sizeof(long long));

    for (i = 0; i < contador; i++) {
        char* temp = _strdup(linhas[i]);
        char* token = strtok(temp, ",");
        int j;
        for (j = 0; j < indiceColuna; j++) 
            token = strtok(NULL, ",");
        if (tipoColuna == 0)
            ((int*)coluna)[i] = atoi(token);
        else if (tipoColuna == 1)
            ((float*)coluna)[i] = atof(token);
        else if (tipoColuna == 2)
            ((char**)coluna)[i] = _strdup(token);
        else if (tipoColuna == 3)
            ((long long*)coluna)[i] = dataParaNumero(token);
        free(temp);
    }

    int trocas = 0;
    switch (escolha) {
        case 1: trocas = SelectionSort(linhas, coluna, tipoColuna, contador); break;
        case 2: trocas = BubbleSort(linhas, coluna, tipoColuna, contador); break;
        case 3: trocas = InsertionSort(linhas, coluna, tipoColuna, contador); break;
        case 4: trocas = CocktailShakerSort(linhas, coluna, tipoColuna, contador); break;
        case 5: trocas = QuickSort(linhas, coluna, tipoColuna, contador); break;
        case 6: trocas = MergeSort(linhas, coluna, tipoColuna, contador); break;
        case 7: trocas = ShellSort(linhas, coluna, tipoColuna, contador); break;
        case 8: trocas = HeapSort(linhas, coluna, tipoColuna, contador); break;
        default: printf("Opcao invalida!\n"); return 1;
    }

    printf("\n--- Linhas ordenadas ---\n");
    for (i = 0; i < contador; i++) {
        printf("%s\n", linhas[i]);
        free(linhas[i]);
    }

    printf("\nTotal de linhas ordenadas: %d\n", contador);
    printf("Total de trocas realizadas: %d\n", trocas);

    if (tipoColuna == 2) {
        char** arr = (char**)coluna;
        for (i = 0; i < contador; i++)
            free(arr[i]);
    }

    free(coluna);
    free(linhas);

    return 0;
}

