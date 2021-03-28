#include <stdio.h>
#include <stdlib.h>

#define NAME (sizeof(char)*10)
#define AGE (sizeof(int))
#define PHONE (sizeof(char)*12)
#define NAMESCOUNT (sizeof(int))

void *pBuffer;

void insert();
// void delete();
void list();
void search();

void main(){
    int option = 0;
    pBuffer = malloc(NAMESCOUNT * 2);

    if (!pBuffer)
    {
        printf("Erro na alocacao de memoria");
        return -1;
    }

    do
    {
        printf("\nInsira o numero referente a opcao escolhida: \n- 1) Registrar pessoa \n- 2) Remover pessoa \n- 3) Buscar \n- 4) Listar \n- 5) Sair \n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert();
            break;

        case 2:
            // delete();
            break;

        case 3:
            search();
            break;

        case 4:
            list();
            break;

        case 5:
            free(pBuffer);
            break;

        default:
            break;
        }

    } while (option != 5);
    
}

void insert() {
    getchar();
    pBuffer = realloc(pBuffer, ( NAMESCOUNT + (*(int*)(pBuffer)) + 1) * ( NAME + AGE + PHONE ) );

    printf("\nInsira o nome a ser registrado: ");
    scanf("%s", (char*)(pBuffer + NAMESCOUNT + *(int*)(pBuffer) * ( NAME + AGE + PHONE )) );

    printf("\nInsira a idade da pessoa: ");
    scanf("%d", (int*)(pBuffer + NAMESCOUNT + *(int*)(pBuffer) * ( NAME + AGE + PHONE ) + NAME ) );

    printf("\nInsira telefone da pessoa com DDD(somente números): ");
    scanf("%s", (char*)(pBuffer + NAMESCOUNT + *(int*)(pBuffer) * ( NAME + AGE + PHONE ) + NAME + AGE ) );

    *(int*)(pBuffer) = *(int*)(pBuffer) + 1;
}

void search() {
    getchar();
    char searchName[10];

    printf("\nInsira o nome da pessoa a ser buscada: ");
    scanf("%s", searchName);

    for (int i = 0; i < *(int*)(pBuffer); i++)
    {
        if ( !strcmp((char*)(pBuffer + NAMESCOUNT + i * ( NAME + AGE + PHONE )), searchName))
        {
            printf("\n%s", (char*)(pBuffer + NAMESCOUNT + i * ( NAME + AGE + PHONE )) );
            printf("\n%d", *(int*)(pBuffer + NAMESCOUNT + i * ( NAME + AGE + PHONE ) + NAME ) );
            printf("\n%s", (char*)(pBuffer + NAMESCOUNT + i * ( NAME + AGE + PHONE ) + NAME + AGE ) );

            break;
        }
        
    }
    
}

void list() {
    for (int i = 0; i < *(int*)(pBuffer); i++)
    {
        printf("\n%s", (char*)(pBuffer + NAMESCOUNT + i * ( NAME + AGE + PHONE )) );
        printf("\n%d", *(int*)(pBuffer + NAMESCOUNT + i * ( NAME + AGE + PHONE ) + NAME ) );
        printf("\n%s", (char*)(pBuffer + NAMESCOUNT + i * ( NAME + AGE + PHONE ) + NAME + AGE ) );
    }
    
}