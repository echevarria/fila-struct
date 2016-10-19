/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: quinho
 *
 * Created on 18 de Outubro de 2016, 22:36
 */

#include <stdio.h>
#include <stdlib.h>


#define TAMANHO 10

typedef struct {
    int fila[TAMANHO];
    int inicio, fim;
} FILA;

void inicializa(FILA *f) {
    f->inicio = 0;
    f->fim = -1;
}

int inserir(FILA *f, int elemento) {
    if (estaCheia(f) == 1) {
        return 0;
    }
    
    f->fim++;
    f->fila[f->fim] = elemento;

    return 1;
}

int remover(FILA *f) {
    if (estaVazia(f) == 1) {
        return 0;
    }
    int elemento;
    elemento = f->fila[f->inicio];
    f->inicio++;
    
    return elemento;
}

int estaCheia(FILA *f) {
    if (f->fim == TAMANHO - 1) {
        return 1;
    }
    return 0;
}

int estaVazia(FILA *f) {
    if (f->fim < f->inicio) {
        return 1;
    }
    return 0;
}

int tamanhoDaFila(FILA *f) {
    return f->fim - f->inicio + 1;
}

int retornaPrimeiroDaFila(FILA *f) {
    if (estaVazia(f) == 1) {
        return 0;
    }
    return f->fila[f->inicio];
}

int retornaUltimoDaFila(FILA *f) {
    if (estaVazia(f) == 1) {
        return 0;
    }
    return f->fila[f->fim];
}

void imprimeFila(FILA *f) {
    int i;
    if (estaVazia(f) == 1) {
        printf("A fila está vazia.\n");
    } else {
        printf("FILA: ");
        for (i = f->inicio; i <= f->fim; i++) {
            if (i == f->fim) {
                printf("%d", f->fila[i]);
            } else {
                printf("%d : ", f->fila[i]);
            }
        }
        printf("\n\n");
    }
    
}

int lerOpcaoMenu() {
    
    int opcao;
    
    printf("\nMenu:");
    printf("\n(1)Insere na fila");
    printf("\n(2)Retira da fila");
    printf("\n(3)Tamanho da fila");
    printf("\n(4)Primeiro da fila");
    printf("\n(5)Ultimo da fila");
    printf("\n(6)Imprime fila");
    printf("\n(0)Sair");
    
    printf("\n\nDigite sua opcao: ");
    scanf("%d", &opcao);
    
    return opcao;
}

int main(int argc, char** argv) {

    FILA f1;
    
    int elemento, retorno, opcao;
    
    inicializa(&f1);
    
    do {
        opcao = lerOpcaoMenu();
        printf("\33[H\33[2J"); // Limpa a tela
        
        switch (opcao) {
            case 0:
                printf("\nSaindo...\n");
                break;
            case 1:
                printf("Digite o elemento: ");
                scanf("%d", &elemento);
                if (inserir(&f1, elemento) == 1) {
                    printf("Elemento inserido na fila com sucesso.\n");
                } else {
                    printf("Elemento NAO inserido.\n FILA CHEIA \n");
                }
                break;
            case 2:
                retorno = remover(&f1);
                if (retorno != 0) {
                    printf("Elemento %d removido da fila com sucesso.\n", retorno);
                } else {
                    printf("Elemento NAO removido.\nFILA VAZIA\n");
                }
                break;
            case 3:
                printf("O tamanho da fila eh: %d\n", tamanhoDaFila(&f1));
                break;
            case 4:
                printf("O primeiro da fila eh: %d\n", retornaPrimeiroDaFila(&f1));
                break;
            case 5:
                printf("O ultimo da fila eh: %d\n", retornaUltimoDaFila(&f1));
                break;
            case 6:
                imprimeFila(&f1);
                break;
        }
        
    } while (opcao != 0);
        

//    imprimiFila(&f1);
//    
//    scanf("%d", &elemento);
//    inserir(&f1, elemento);
//    
//    scanf("%d", &elemento);
//    inserir(&f1, elemento);
//
//    imprimiFila(&f1);

    return (EXIT_SUCCESS);
}

