#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *mainArray;

void insertionSort(int size);
void selectionSort(int size);
void quickSort(int left, int right);
void mergeSort(int start, int end);
void merge(int start, int middle, int end);
void printArray(int size);
int verifyArray(int size);

void main() {
    srand(time(NULL));

    mainArray = (int *)malloc(sizeof(int));
    if (!mainArray)
    {
        printf("Erro na alocacao de memoria");
        return -1;
    }

    int arraySize = 0, option = 0;

do
{


    printf("\nInsira o número referente ao método de sort escolhido:\n1) Insertion Sort\n2) Selection Sort\n3) Quick Sort\n4) Merge Sort\n5) Sair\n");
    scanf("%d", &option);
    if (option < 5 && option > 0)
    {
        do
        {
            printf("\nInsira o tamanho do array desejado: ");
            scanf("%d", &arraySize);
        } while (arraySize < 1);

        if (arraySize > 0)
        {
            mainArray = realloc(mainArray, sizeof(int) * arraySize);
            for (int i = 0; i < arraySize; i++)
                {
                    mainArray[i] = rand() % 100;
                }
        }
    }
    
    switch (option)
    {
    case 1:
        insertionSort(arraySize);
        printArray(arraySize);
        break;

    case 2:
        selectionSort(arraySize);
        printArray(arraySize);
        break;

    case 3:
        quickSort(0, arraySize);
        printArray(arraySize);
        break;

    case 4:
        mergeSort(0, arraySize);
        printArray(arraySize);
        break;

    case 5:
        free(mainArray);
        break;
    
    default:
        break;
    }
} while (option != 5);

    
};

void insertionSort(int size) {
    int currentNumber, aux;
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j> 0 && mainArray[j] < mainArray[j-1] && j < size; j -= 1)
        {
            aux = mainArray[j];
            mainArray[j] = mainArray[j - 1];
            mainArray[j - 1] = aux;
        }
    } 
};

void selectionSort(int size) {    
    int smallestNumber, smallestNumberIndex, aux;

    for (int i = 0; i < size-1; i++)
    {
        smallestNumber = mainArray[i];
        for (int j = i+1; j < size; j++)
        {
            if (mainArray[j] < smallestNumber)
            {
                smallestNumber = mainArray[j];
                smallestNumberIndex = j;
            }
        }
        aux = mainArray[i];
        mainArray[i] = mainArray[smallestNumberIndex];
        mainArray[smallestNumberIndex] = aux;
        smallestNumberIndex = i+1;
    }
};

void quickSort(int left, int right) {
    int aux, i = left, j = right, pivot = mainArray[(left + right) / 2];

    do
    {
        while (mainArray[i] < pivot)
        {
            i++;
        }
        while (mainArray[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            aux = mainArray[i];
            mainArray[i] = mainArray[j];
            mainArray[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j)
    {
        quickSort(left, j);
    }
    if (right > i)
    {
        quickSort(i, right);
    }
};

void mergeSort(int start, int end) {
    if (start < end)
    {
        int middle = (start + end) / 2;

        mergeSort(start, middle);
        mergeSort(middle + 1, end);
        merge(start, middle, end);
    }
    
};

void merge(int start, int middle, int end) {
    int i = 0, startAux = start, middleAux = middle + 1, size = end - start + 1, auxArray[size];

    while(startAux <= middle && middleAux <= end){
        if(mainArray[startAux] < mainArray[middleAux]) {
            auxArray[i] = mainArray[startAux];
            startAux++;
        } else {
            auxArray[i] = mainArray[middleAux];
            middleAux++;
        }
        i++;
    }

    while(startAux <= middle){
        auxArray[i] = mainArray[startAux];
        i++;
        startAux++;
    }

    while(middleAux <= end) {
        auxArray[i] = mainArray[middleAux];
        i++;
        middleAux++;
    }

    for(i = start; i <= end; i++){
        mainArray[i] = auxArray[i-start];
    }
};

void printArray(int size) {
    printf("\n%d", mainArray[0]);
    for (int i = 1; i < size; i++)
    {
        printf(", %d", mainArray[i]);
    }
    printf("\n\n");

    if (verifyArray(size))
    {
        printf("O array foi ordenado com sucesso!\n");
    } else {
        printf("O array não foi ordenado apropriadamente!\n");
    }
    
}

int verifyArray(int size) {
    for (int i = 0; i < size-1; i++)
    {
        if (mainArray[i] > mainArray[i+1])
        {
            return 0;
        } 
    }
    return 1;
}
