#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert();
void removeName();
void list();

int listSize = 0;
char* nameList;

void main(){
    int option = 0;
    nameList = (char *)malloc(sizeof(char) * 2);

    do
    {
    printf("\nInsira o numero referente a opcao escolhida: \n- 1) Adicionar nome \n- 2) Remover nome \n- 3) Listar \n- 4) Sair \n");
    scanf("%d",&option);
        switch (option)
        {
        case 1:
            insert();
            break;
        
        case 2:
            removeName();
            break;

        case 3:
            list();
            break;

        case 4:
            free(nameList);
            break;

        default:
            break;
        }

    } while (option != 4);
}

void insert(){
    fgetc(stdin);
    if (listSize != 0)
    {
        nameList[listSize]=',';
        listSize++;
        nameList = realloc(nameList, listSize * sizeof(char) + 2);
        nameList[listSize]=' ';
        listSize++;
        nameList = realloc(nameList, listSize * sizeof(char) + 2);
    }
    for (int i = listSize; ((nameList[i] = getchar()) != '\n') && nameList[i] != '\0'; i++)
    {
        listSize++;
        nameList = realloc(nameList, listSize * sizeof(char) + 2);
    }
    nameList[listSize] = '\0';
}

void removeName(){
    for (; (nameList[listSize] != ',') && (listSize != 0); listSize--);
    nameList = realloc(nameList, listSize * sizeof(char) + 1);
    nameList[listSize]= '\0';
}

void list(){
    printf("%s\n",nameList);
}