#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define INT (sizeof(int))
#define OPTION (int*)(pBuffer)
#define INTERATOR *(int*)(pBuffer + sizeof(int))
#define NAME (sizeof(char)*10)
#define AGE (sizeof(int))
#define PHONE (sizeof(char)*12)
#define PERSONCOUNT lista->nCount
#define SEARCHNAME (char *)(pBuffer + 2 * sizeof(int))
#define SHOULDSORT (char *)(pBuffer + 3 * sizeof(int))
#define SORTOPTION (int *)(pBuffer + sizeof(int) * 2)
#define SORTPARAMETER (int *)(pBuffer + sizeof(int) * 3)


struct info {
    char nome[30];
    int idade;
    int telefone;
};
typedef struct info SInfo;

struct nodo {
    SInfo dado;
    struct nodo *pPrevious;
    struct nodo *pNext;
};
typedef struct nodo SNodo;

struct lista{
    unsigned int nCount;
    SNodo *pLast;
    SNodo *pFirst;
};
typedef struct lista SLista;


void *pBuffer;
SLista *lista;

void insert();
void delete();
void list();
void search();
void sort();

void main() {
    lista = (SLista *) malloc(sizeof(SLista));
    if (!lista)
    {
        printf("Erro na alocação de memória");
        return -1;
    }

    PERSONCOUNT = 0;

    pBuffer = malloc(INT * 2);
    if (!pBuffer)
    {
        printf("Erro na alocação de memória");
        return -1;
    }

    do
    {
        printf("\nInsira o numero referente a opcao escolhida: \n- 1) Registrar pessoa \n- 2) Remover pessoa \n- 3) Buscar \n- 4) Listar \n- 5) Sair \n");
        scanf("%d", OPTION);
        switch (*OPTION)
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
            break;

        default:
            break;
        }

    } while (*OPTION != 5);
    
    free(pBuffer);
}

void insert() {
    getchar();
    SNodo *newPerson;
    newPerson = (SNodo *) malloc(sizeof(SNodo));
    if (!newPerson)
    {
        printf("Erro na alocação de memória");
        return -1;
    }
    
    printf("\nInsira o nome a ser registrado: ");
    fgets(newPerson->dado.nome, 30, stdin);
    newPerson->dado.nome[strlen(newPerson->dado.nome) - 1] = '\0';

    printf("\nInsira a idade da pessoa: ");
    scanf("%d", &newPerson->dado.idade);

    printf("\nInsira telefone da pessoa com DDD(somente números): ");
    scanf("%d", &newPerson->dado.telefone);

    if (PERSONCOUNT == 0)
    {
        newPerson->pPrevious = NULL;
        lista->pFirst = newPerson;
    }else {
        newPerson->pPrevious = lista->pLast;
        newPerson->pPrevious->pNext = newPerson;
    }
    
    newPerson->pNext = NULL;
    lista->pLast = newPerson;
    (PERSONCOUNT)++;
}

void delete() {
    getchar();
    pBuffer = realloc(pBuffer, INT * 2 + sizeof(char) * 30);
    SNodo *aux; 
    aux = (SNodo *) malloc(sizeof(SNodo));
    if (!aux)
    {
        printf("Erro na alocação de memória");
        return -1;
    }

    printf("\nInsira o nome da pessoa a ser excluida: ");
    fgets(SEARCHNAME, 30, stdin);
    *(char *)(pBuffer + INT * 2 + (strlen(SEARCHNAME) - 1) * sizeof(char)) = '\0';

    for (aux = lista->pFirst; aux != NULL; aux = aux->pNext )
    {
        if (!strcmp(aux->dado.nome, SEARCHNAME))
        {
            if (PERSONCOUNT == 1) // Testa se é a última pessoa
            {
                lista->pFirst = NULL;
                lista->pLast = NULL;
            }else if(aux->pPrevious == NULL) { // Testa se é a primeira pessoa
                aux->pNext->pPrevious = NULL;
                lista->pFirst = aux->pNext;
            }else if(aux->pNext == NULL) { // Testa se é a última
                aux->pPrevious->pNext = NULL;
                lista->pLast = aux->pPrevious;
            }else {
                aux->pPrevious->pNext = aux->pNext;
                aux->pNext->pPrevious = aux->pPrevious;
            }
        }   
    }

    pBuffer = realloc(pBuffer, INT * 2);
    free(aux);

    (PERSONCOUNT)--; 
}

void list() {
    pBuffer = realloc(pBuffer, INT * 4 + sizeof(char));
    
    do
    {
        getchar();
        printf("\nDeseja reordenar a agenda?[S/n] ");
        *SHOULDSORT = getchar();
    } while (*SHOULDSORT != 'S' && *SHOULDSORT != 'n');
    
    if (*SHOULDSORT == 'S')
    {
        do
        {
            printf("\nInsira o numero referente a opcao escolhida: \n- 1) Nome crescente \n- 2) Nome decrescente \n- 3) Idade crescente \n- 4) Idade decrescente \n- 5) Telefone crescente \n- 6) Telefone decrescente \n- 7) Cancelar \n");
            scanf("%d", SORTOPTION);
            switch (*SORTOPTION)
            {
                case 1:
                    *SORTPARAMETER = (int) offsetof(SNodo, dado.nome);
                    sort();
                    break;
                case 2:
                    *SORTPARAMETER = (int) offsetof(SNodo, dado.nome);
                    sort();  
                    break;
                case 3:
                    *SORTPARAMETER = (int) offsetof(SNodo, dado.idade);
                    sort();
                    break;
                case 4:
                    *SORTPARAMETER = (int) offsetof(SNodo, dado.idade);
                    sort();
                    break;
                case 5:
                    *SORTPARAMETER = (int) offsetof(SNodo, dado.telefone);
                    sort();
                    break;
                case 6:
                    *SORTPARAMETER = (int) offsetof(SNodo, dado.telefone);
                    sort();
                    break;
            
                default:
                    break;
            }
        } while (*SORTOPTION < 1 || *SORTOPTION > 7 );
    }

    SNodo *aux; 
    aux = (SNodo *) malloc(sizeof(SNodo));
    if (!aux)
    {
        printf("Erro na alocação de memória");
        return -1;
    }

    for (aux = lista->pFirst; aux != NULL; aux = aux->pNext )
    {
        printf("\nNome: %s", aux->dado.nome);
        printf("\nIdade: %d", aux->dado.idade);
        printf("\nTelefone: %d \n", aux->dado.telefone);
    }
    
    pBuffer = realloc(pBuffer, INT * 2);
    free(aux);
}

void search() {
    getchar();
    pBuffer = realloc(pBuffer, INT * 2 + sizeof(char) * 30);
    SNodo *aux; 
    aux = (SNodo *) malloc(sizeof(SNodo));
    if (!aux)
    {
        printf("Erro na alocação de memória");
        return -1;
    }

    printf("\nInsira o nome da pessoa a ser buscada: ");
    fgets(SEARCHNAME, 30, stdin);
    *(char *)(pBuffer + INT * 2 + (strlen(SEARCHNAME) - 1) * sizeof(char)) = '\0';

    for (aux = lista->pFirst; aux != NULL; aux = aux->pNext )
    {
        if (!strcmp(aux->dado.nome, SEARCHNAME))
        {
            printf("\nNome: %s", aux->dado.nome);
            printf("\nIdade: %d", aux->dado.idade);
            printf("\nTelefone: %d \n", aux->dado.telefone);
        }   
    }

    pBuffer = realloc(pBuffer, INT * 2);
    free(aux);
}

void sort() {
    SNodo *aux; 
    aux = (SNodo *) malloc(sizeof(SNodo));
    if (!aux)
    {
        printf("Erro na alocação de memória");
        return -1;
    }

    if (*SORTOPTION % 2 == 0) // Decrescente
    {
       if (*SORTOPTION < 3) // String
       {
            for (INTERATOR = 0; INTERATOR < PERSONCOUNT - 1; (INTERATOR)++) // Garante que a agenda vai ser inteirada por completo
            {
                for (aux = lista->pFirst; aux->pNext != NULL; aux = aux->pNext) // Laço até antes de o nodo depois do auxiliar ser nulo
                {
                    if (strcmp((char *)(aux + *SORTPARAMETER), (char *)(aux->pNext + *SORTPARAMETER)) < 0) // Compara a informação atual do nodo com a próxima
                    {
                        if (aux == lista->pFirst) // Testa se o nodo atual é o primeiro da agenda
                       {
                           if (aux->pNext == lista->pLast) // Testa se o próximo nodo é o último da agenda
                           {
                               aux->pNext = NULL;
                               aux->pPrevious = lista->pLast;
                               lista->pLast->pPrevious = NULL; 
                               lista->pLast->pNext = aux;
                               lista->pFirst = aux->pPrevious;
                               lista->pLast = aux;
                               
                           }else {
                            lista->pFirst = aux->pNext;
                            aux->pNext->pPrevious = aux->pPrevious;
                            aux->pPrevious = aux->pNext;
                            aux->pNext = aux->pPrevious->pNext;
                            aux->pPrevious->pNext = aux;
                            aux->pNext->pPrevious = aux;
                           }
                       } else {
                            if (aux->pNext == lista->pLast) // Testa se o próximo nodo é o último da agenda
                            {
                                lista->pLast = aux;
                            } 
                            aux->pNext->pPrevious = aux->pPrevious;
                            aux->pPrevious->pNext = aux->pNext;
                            aux->pPrevious = aux->pNext;
                            aux->pNext = aux->pPrevious->pNext;
                            aux->pPrevious->pNext = aux; 
                       }
                       aux = aux->pPrevious;
                    }
                }
                
            }
       } else { // Int
            for (INTERATOR = 0; INTERATOR < PERSONCOUNT - 1; (INTERATOR)++)
            {
                for (aux = lista->pFirst; aux->pNext != NULL; aux = aux->pNext)
                {
                    if (*(int *)((char *)aux + *SORTPARAMETER) < *(int *)((char *)aux->pNext + *SORTPARAMETER))
                   {
                       if (aux == lista->pFirst)
                       {
                           if (aux->pNext == lista->pLast)
                           {
                               aux->pNext = NULL;
                               aux->pPrevious = lista->pLast;
                               lista->pLast->pPrevious = NULL; 
                               lista->pLast->pNext = aux;
                               lista->pFirst = aux->pPrevious;
                               lista->pLast = aux;
                               
                           }else {
                            lista->pFirst = aux->pNext;
                            aux->pNext->pPrevious = aux->pPrevious;
                            aux->pPrevious = aux->pNext;
                            aux->pNext = aux->pPrevious->pNext;
                            aux->pPrevious->pNext = aux;
                            aux->pNext->pPrevious = aux;
                           }
                       } else {
                            if (aux->pNext == lista->pLast)
                            {
                                lista->pLast = aux;
                            } 
                            aux->pNext->pPrevious = aux->pPrevious;
                            aux->pPrevious->pNext = aux->pNext;
                            aux->pPrevious = aux->pNext;
                            aux->pNext = aux->pPrevious->pNext;
                            aux->pPrevious->pNext = aux; 
                       }
                       aux = aux->pPrevious;
                   }
                }
                
            }           
       }
       
    } else { // Crescente
        if (*SORTOPTION < 3) // String
        {
            for (INTERATOR = 0; INTERATOR < PERSONCOUNT - 1; (INTERATOR)++)
            {
                for (aux = lista->pFirst; aux->pNext != NULL; aux = aux->pNext)
                {
                    if (strcmp((char *)(aux + *SORTPARAMETER), (char *)(aux->pNext + *SORTPARAMETER)) > 0)
                    {
                        if (aux == lista->pFirst)
                       {
                           if (aux->pNext == lista->pLast)
                           {
                               aux->pNext = NULL;
                               aux->pPrevious = lista->pLast;
                               lista->pLast->pPrevious = NULL; 
                               lista->pLast->pNext = aux;
                               lista->pFirst = aux->pPrevious;
                               lista->pLast = aux;
                               
                           }else {
                            lista->pFirst = aux->pNext;
                            aux->pNext->pPrevious = aux->pPrevious;
                            aux->pPrevious = aux->pNext;
                            aux->pNext = aux->pPrevious->pNext;
                            aux->pPrevious->pNext = aux;
                            aux->pNext->pPrevious = aux;
                           }
                       } else {
                            if (aux->pNext == lista->pLast)
                            {
                                lista->pLast = aux;
                            } 
                            aux->pNext->pPrevious = aux->pPrevious;
                            aux->pPrevious->pNext = aux->pNext;
                            aux->pPrevious = aux->pNext;
                            aux->pNext = aux->pPrevious->pNext;
                            aux->pPrevious->pNext = aux; 
                       }
                       aux = aux->pPrevious;
                    }
                    
                }
                
            }
        } else { // Int
            for (INTERATOR = 0; INTERATOR < PERSONCOUNT - 1; (INTERATOR)++)
            {
                
                for (aux = lista->pFirst; aux->pNext != NULL; aux = aux->pNext)
                {
                   if (*(int *)((char *) aux + *SORTPARAMETER) > *(int *)((char *) aux->pNext + *SORTPARAMETER))
                   {
                       if (aux == lista->pFirst)
                       {
                           if (aux->pNext == lista->pLast)
                           {
                               aux->pNext = NULL;
                               aux->pPrevious = lista->pLast;
                               lista->pLast->pPrevious = NULL; 
                               lista->pLast->pNext = aux;
                               lista->pFirst = aux->pPrevious;
                               lista->pLast = aux;
                               
                           }else {
                            lista->pFirst = aux->pNext;
                            aux->pNext->pPrevious = aux->pPrevious;
                            aux->pPrevious = aux->pNext;
                            aux->pNext = aux->pPrevious->pNext;
                            aux->pPrevious->pNext = aux;
                            aux->pNext->pPrevious = aux;
                           }
                       } else {
                            if (aux->pNext == lista->pLast)
                            {
                                lista->pLast = aux;
                            } 
                            aux->pNext->pPrevious = aux->pPrevious;
                            aux->pPrevious->pNext = aux->pNext;
                            aux->pPrevious = aux->pNext;
                            aux->pNext = aux->pPrevious->pNext;
                            aux->pPrevious->pNext = aux; 
                       }
                       aux = aux->pPrevious;
                   }
                    
                }
                
            }
        }
    }
}