#include <stdio.h>
#include <stdlib.h>

void insert();
void removeName();
void list();

// Sugestão de melhoria: Não declarar as variaveis globalmente
int listSize = 0;
char *nameList;

void main()
{
    int option = 0;
    nameList = (char *)malloc(sizeof(char) * 2);
    if (!nameList)
    {
        printf("Erro na alocacao de memoria");
        return -1;
    }

    do
    {
        printf("\nInsira o numero referente a opcao escolhida: \n- 1) Adicionar nome \n- 2) Remover nome \n- 3) Listar \n- 4) Sair \n");
        scanf("%d", &option);
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

void insert()
{
    fgetc(stdin);
    printf("Insira o nome: ");
    if (listSize != 0) // Separação dos nomes por ", "
    {
        nameList[listSize] = ',';
        listSize++;
        nameList = realloc(nameList, listSize * sizeof(char) + 2);
        nameList[listSize] = ' ';
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

void removeName()
{
    getchar();
    char *inputName = (char *)malloc(sizeof(char) * 2);
    int inputNameSize = 0;
    if (!inputName)
    {
        printf("Erro na alocacao de memoria");
        return -1;
    }

    printf("Insira o nome a ser removido: ");
    for (int count = 0; ((inputName[count] = getchar()) != '\n') && inputName[count] != '\0'; count++)
    {
        inputNameSize++;
        inputName = realloc(inputName, inputNameSize * sizeof(char) + 2);
    }
    inputName[inputNameSize] = '\0';

    int i, sizeCounter;
    for (i = 0; i < listSize && nameList[i] != '\0'; i++)
    {
        if (i <= 2 || nameList[i - 2] == ',') // Teste para saber se se trata do primeiro nome ou não.
        {
            if (i <= 2) // Caso seja o primeiro nome garante que a variável a ser utilizada seja 0
            {
                sizeCounter = 0;
            }else{
                sizeCounter = i;
            }
            
            for (; nameList[sizeCounter] != ',' && nameList[sizeCounter] != '\0'; sizeCounter++); // Conta o tamanho do nome na lista
             if ((sizeCounter - i) == inputNameSize || sizeCounter == inputNameSize)
            {
                int j, k, l;
                if (i <= 2) // Caso seja o primeiro nome garante que aa variáveis a serem utilizadas sejam 0
                {
                    j = 0;
                    l = 0;
                }else{
                    j = i;
                    l = i;
                }

                for (k = 0; nameList[j] == inputName[k] && k < (sizeCounter - l); j++, k++); // Compara os nomes de letra em letra
                if (k == inputNameSize)
                {
                    if((i == 0 || i <= 2) && !(listSize > inputNameSize)) { // Testa se é o primeiro e único nome na lista
                        listSize = 0;
                        nameList = realloc(nameList, sizeof(char));
                        nameList[0] = '\0';
                    }else if (nameList[sizeCounter] == '\0') // Testa se é o último nome da lista
                    {
                        listSize -= inputNameSize + 2;
                        nameList = realloc(nameList, sizeof(char) * (listSize + 1));
                        nameList[listSize] = '\0'; 
                    }else {
                    for (k = i; nameList[k + inputNameSize + 1] != '\0'; k++) // Switch para a situação em que é um nome no meio da lista
                    {
                        nameList[k] = nameList[k + inputNameSize + 2];
                    }
                    listSize -= (inputNameSize + 2);
                    nameList = realloc(nameList, sizeof(char) * (listSize + 1));
                    i--;
                    }
                }
            }
            sizeCounter = 0;
        }
    }
free(inputName);
}

void list()
{
    if (listSize == 0)
    {
        printf("A lista de nomes está vazia!\n");
    }else {
    printf("%s\n", nameList);
    }
}