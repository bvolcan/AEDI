#include <stdio.h>
#include <stdlib.h>

#define INT (sizeof(int))
#define NAME (sizeof(char) * 30)
#define SEARCHNAME (char *)(pBuffer + 3 * sizeof(int))
#define OPTION *(int*)(pBuffer)
#define LISTSIZE *(int*)(pBuffer + sizeof(int))
#define INTERATOR *(int*)(pBuffer + 2 * sizeof(int))
#define INTERATOR2 *(int*)(pBuffer + 3 * sizeof(int))

typedef struct{
    char nome[30];
    int idade;
    int altura;
}Pessoa;

Pessoa pessoas[10];
void *pBuffer;

void insert();
void delete();
void list();
void search();

void main() {
    pBuffer = malloc(INT * 3);
    if (!pBuffer)
    {
        printf("Erro na alocação de memória");
        return -1;
    }

    OPTION = 0;
    LISTSIZE = 0;

    do
    {
        printf("\nInsira o numero referente a opcao escolhida: \n- 1) Registrar pessoa \n- 2) Remover pessoa \n- 3) Buscar \n- 4) Listar \n- 5) Sair \n");
        scanf("%d", (int*)(pBuffer));
        switch (OPTION)
        {
        case 1:
            insert();
            break;

        case 2:
            delete();
            break;

        case 3:
            search();
            break;

        case 4:
            list();
            break;

        default:
            break;
        }

    } while (OPTION != 5);
    
    free(pBuffer);
}

void insert() {
    getchar();
    if (LISTSIZE == 10)
    {
        printf("A lista já alcançou o seu limite de armazenamento.\nExclua algum registro para poder registrar novamente.\n");
    } else {
    printf("\nInsira o nome a ser registrado: ");
    fgets(pessoas[LISTSIZE].nome, 30, stdin);
    pessoas[LISTSIZE].nome[strlen(pessoas[LISTSIZE].nome) - 1] = '\0';

    printf("\nInsira a idade da pessoa: ");
    scanf("%d", &pessoas[LISTSIZE].idade);
    getchar();

    printf("\nInsira a altura da pessoa: ");
    scanf("%d", &pessoas[LISTSIZE].altura);
    getchar();

    LISTSIZE = LISTSIZE + 1;
    }
}

void delete() {
    getchar();

    pBuffer = realloc(pBuffer, INT * 4 + NAME );

    printf("\nInsira o nome da pessoa a ser excluida: ");
    fgets(SEARCHNAME, 30, stdin);
    *(char *)(pBuffer + INT * 3 + (strlen(SEARCHNAME) - 1) * sizeof(char)) = '\0';

    for (INTERATOR = 0; INTERATOR < LISTSIZE; (INTERATOR)++)
    {
        if (!strcmp(pessoas[INTERATOR].nome, SEARCHNAME))
        {
            for (INTERATOR2 = INTERATOR; INTERATOR2 < LISTSIZE; (INTERATOR2)++)
            {
                if (INTERATOR2 + 1 < LISTSIZE)
                {
                    pessoas[INTERATOR2] = pessoas[INTERATOR2 + 1];
                }  
            }   
        } 
    }

    pBuffer = realloc(pBuffer, INT * 3);
    
    (LISTSIZE)--;
}

void list() {
    if (LISTSIZE == 0)
    {
        printf("\nNenhuma pessoa foi registrada\n");
    }else{
        for (INTERATOR = 0; INTERATOR < LISTSIZE; (INTERATOR)++)
        {
            printf("\nNome: %s", pessoas[INTERATOR].nome);
            printf("\nIdade: %d", pessoas[INTERATOR].idade);
            printf("\nAltura: %d \n", pessoas[INTERATOR].altura);
        }
        
    }
    
}
void search() {
    getchar();

    pBuffer = realloc(pBuffer, INT * 3 + NAME );

    printf("\nInsira o nome da pessoa a ser buscada: ");
    fgets(SEARCHNAME, 30, stdin);
    *(char *)(pBuffer + INT * 3 + (strlen(SEARCHNAME) - 1) * sizeof(char)) = '\0';

    for (INTERATOR = 0; INTERATOR < LISTSIZE; (INTERATOR)++)
    {
        if (!strcmp(pessoas[INTERATOR].nome, SEARCHNAME))
        {
            printf("\nNome: %s", pessoas[INTERATOR].nome);
            printf("\nIdade: %d", pessoas[INTERATOR].idade);
            printf("\nAltura: %d \n", pessoas[INTERATOR].altura);
        }
        
    }

    pBuffer = realloc(pBuffer, INT * 3);
    
}