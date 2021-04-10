#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    int idade;
    int altura;
}Pessoa;


void main() {
    Pessoa *list;
    list = (Pessoa *) malloc(sizeof(Pessoa));
    if (!list)
    {
        printf("Erro na alocação de memória");
    }
    
    int listSize = 0;
    char loop;

    printf("Deseja cadastrar um(a) novo(a) usuário(a)?[S/n] ");
    while ((loop = getchar()) == 'S')
    {
        getchar();

        printf("Insira o nome do(a) usuário(a): ");
        fgets(list[listSize].nome, 30, stdin);
        list[listSize].nome[strlen(list[listSize].nome) - 1] = '\0';

        printf("Insira a idade do(a) usuário(a): ");
        scanf("%d", &list[listSize].idade);
        getchar();

        printf("Insira a altura do(a) usuário(a): ");
        scanf("%d", &list[listSize].altura);
        getchar();

        listSize++;
        list = realloc(list, (listSize + 1) * sizeof(Pessoa));
        printf("\nDeseja cadastrar um novo usuário?[S/n]");
    }

    if (listSize == 0)
    {
        printf("\nNenhum usuário foi cadastrado\n\n");
    }else {
        printf("\nUsuários registrados: \n");
    }

    for (int i = 0; i < listSize; i++)
    {
        printf("\nUsuário n.%d:", (i+1));
        printf("\nNome: %s", list[i].nome);
        printf("\nIdade: %d", list[i].idade);
        printf("\nAltura: %d cm \n", list[i].altura);
    }
    
    
    free(list);
}