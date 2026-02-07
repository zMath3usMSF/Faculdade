#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TAMANHO_ALFABETO 26

typedef struct NoTrie{
    struct NoTrie* filhos[TAMANHO_ALFABETO];
    bool ehFimDePalavra;
} NoTrie;

NoTrie* criarNoTrie(){
    NoTrie* novo = (NoTrie*)malloc(sizeof(NoTrie));
    novo->ehFimDePalavra = false;
    for(int i = 0; i < TAMANHO_ALFABETO; i++){
        novo->filhos[i] = NULL;
    }
    return novo;
}

void normalizar(const char* entrada, char* saida){
    int j = 0;
    for(int i = 0; entrada[i] != '\0'; i++){
        char c = entrada[i];
        if(c >= 'A' && c <= 'Z') c += 32;
        if(c >= 'a' && c <= 'z') saida[j++] = c; 
    }
}

void inserirTrie(NoTrie* raiz, const char* palavra){
    NoTrie* atual = raiz;
    for(int i = 0; palavra[i] != '\0'; i++){
        int indice = palavra[i] - 'a';
        if(atual->filhos[indice] == NULL){
            atual->filhos[indice] = criarNoTrie();
        }
        atual = atual->filhos[indice];
    }
    atual->ehFimDePalavra = true;
}

bool buscarTrie(NoTrie* raiz, const char* palavra){
    NoTrie* atual = raiz;
    for(int i = 0; palavra[i] != '\0'; i++){
        int indice = palavra[i] - 'a';
        if(atual->filhos[indice] == NULL){
            return false;
        }
        atual = atual->filhos[indice];
    }
    return atual != NULL && atual->ehFimDePalavra;
}

void listarPalavras(NoTrie* no, char* buffer, int nivel){
    if(no->ehFimDePalavra){
        buffer[nivel] = '\0';
        printf("%s ", buffer);
    }
    for(int i = 0; i < TAMANHO_ALFABETO; i++){
        if(no->filhos[i] != NULL){
            buffer[nivel] = 'a' + i;
            listarPalavras(no->filhos[i], buffer, nivel + 1);
        }
    }
}

void liberarTrie(NoTrie* no){
    for(int i = 0; i < TAMANHO_ALFABETO; i++){
        if(no->filhos[i] != NULL){
            liberarTrie(no->filhos[i]);
        }
    }
    free(no);
}

int main(){
    printf("\n==== Trie ====\n");
    NoTrie* raizTrie = criarNoTrie();
    char normalizada[100];

    normalizar("Pegadas de Lama", normalizada);
    inserirTrie(raizTrie, normalizada);
    normalizar("Chave perdida", normalizada);
    inserirTrie(raizTrie, normalizada);
    normalizar("Livro com pagina faltando", normalizada);
    inserirTrie(raizTrie, normalizada);
    normalizar("Lencol manchado", normalizada);
    inserirTrie(raizTrie, normalizada);
    normalizar("Gaveta perdida", normalizada);
    inserirTrie(raizTrie, normalizada);

    printf("Palavras na Trie: ");
    char buffer[100];
    listarPalavras(raizTrie, buffer, 0);
    printf("\n");
    normalizar("Lencol manchado", normalizada);
    printf("Buscar 'lencolmanchado' (Trie): %s\n", buscarTrie(raizTrie, normalizada) ? "Encontrado" : "Nao encontrado");
    normalizar("Oculos", normalizada);
    printf("Buscar 'oculos' (Trie): %s\n", buscarTrie(raizTrie, normalizada) ? "Encontrado" : "Nao encontrado");

    liberarTrie(raizTrie);
}