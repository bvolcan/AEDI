#include <stdio.h>
#include <stdlib.h>

#define NAME (sizeof(char)*10)
#define AGE (sizeof(int))
#define PHONE (sizeof(char)*12)
#define NAMESCOUNT (sizeof(int))

void *pBuffer;

void insert();
void delete();
void list();
void search();

void main(){
    int option = 0;
    pBuffer = malloc(NAMESCOUNT);
    *(int*)(pBuffer) = 0;

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
            delete();
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

void delete() {
    getchar();
    char deleteName[10];

    printf("\nInsira o nome da pessoa a ser removida da lista: ");
    scanf("%s", deleteName);

    for (int i = 0; i < *(int*)(pBuffer); i++)
    {
        if ( !strcmp((char*)(pBuffer + NAMESCOUNT + i * ( NAME + AGE + PHONE )), deleteName))
        {
            for (int j = i; j < *(int*)(pBuffer); j++)
            {
                if (j+1 >= *(int*)(pBuffer))
                {
                    *(char*)(pBuffer + NAMESCOUNT + j * ( NAME + AGE + PHONE )) = '\0';
                    *(int*)(pBuffer + NAMESCOUNT + j * ( NAME + AGE + PHONE ) + NAME ) = 0;
                    *(char*)(pBuffer + NAMESCOUNT + j * ( NAME + AGE + PHONE ) + NAME + AGE ) = '\0';
                }else{
                    strcpy((char*)(pBuffer + NAMESCOUNT + j * ( NAME + AGE + PHONE )), (char*)(pBuffer + NAMESCOUNT + (j+1) * ( NAME + AGE + PHONE )));
                    *(int*)(pBuffer + NAMESCOUNT + j * ( NAME + AGE + PHONE ) + NAME ) = *(int*)(pBuffer + NAMESCOUNT + (j+1) * ( NAME + AGE + PHONE ) + NAME );
                    strcpy((char*)(pBuffer + NAMESCOUNT + j * ( NAME + AGE + PHONE ) + NAME + AGE ), (char*)(pBuffer + NAMESCOUNT + (j+1) * ( NAME + AGE + PHONE ) + NAME + AGE ));
                }     
            }

            *(int*)(pBuffer) = *(int*)(pBuffer) - 1;
        }
    }

    pBuffer = realloc(pBuffer, ( NAMESCOUNT + (*(int*)(pBuffer)) + 1) * ( NAME + AGE + PHONE ) );
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
            printf("\nNome: %s", (char*)(pBuffer + NAMESCOUNT + i * ( NAME + AGE + PHONE )) );
            printf("\nIdade: %d", *(int*)(pBuffer + NAMESCOUNT + i * ( NAME + AGE + PHONE ) + NAME ) );
            printf("\nTelefone: %s\n", (char*)(pBuffer + NAMESCOUNT + i * ( NAME + AGE + PHONE ) + NAME + AGE ) );

        }
    }
    
}

void list() {
    for (int i = 0; i < *(int*)(pBuffer); i++)
    {
        printf("\nNome: %s", (char*)(pBuffer + NAMESCOUNT + i * ( NAME + AGE + PHONE )) );
        printf("\nIdade: %d", *(int*)(pBuffer + NAMESCOUNT + i * ( NAME + AGE + PHONE ) + NAME ) );
        printf("\nTelefone: %s\n", (char*)(pBuffer + NAMESCOUNT + i * ( NAME + AGE + PHONE ) + NAME + AGE ) );
    }
    if (*(int*)(pBuffer) == 0)
    {
        printf("A lista esta vazia\n");
    }
}