#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

Node* createNewNode();
Node* insertNewNode(Node* node, int number);
int getBalanceFactor(Node* currentNode);
Node* rotateLeft(Node* currentNode);
Node* rotateRight(Node* currentNode);
int updateHeight(Node* currentNode);

void main(){
    srand(time(0));
    int nodesQuantity = 0;

    printf("Insira a quantidade de nodos a ser gerado: ");

    if (scanf("%d", &nodesQuantity) <= 0)
    {
        return -1;
    };

    Node *root = NULL;

    for (int i = 0; i < nodesQuantity; i++)
    {
       root = insertNewNode(root, rand() % 100);
    }
    
}

Node* insertNewNode(Node* node, int number){
    // Node* auxNode = createNewNode();

    if (node == NULL){
        return (createNewNode(number));
    }

    if (number < node->value){
        node->left = insertNewNode(node->left, number);
    }else {
        node->right = insertNewNode(node->right, number);
    }

    node->height = updateHeight(node);

    int nodeBalance = getBalanceFactor(node);

    if (nodeBalance > 1){
        if(getBalanceFactor(node->left) < 0){
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }else if (nodeBalance < -1) {
        if(getBalanceFactor(node->right) > 0){
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }

    return node;
};

Node* createNewNode(int number){
    Node *newNode = (Node*) malloc(sizeof(Node));

    newNode->value = number;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return(newNode);
};

int getBalanceFactor(Node* currentNode){
    if(currentNode == NULL)
    {
        return 0;
    };
    int leftHeight = (currentNode->left == NULL) ? 0 : currentNode->left;
    int rightHeight = (currentNode->right == NULL) ? 0 : currentNode->right;

    return leftHeight - rightHeight;
};

Node* rotateLeft(Node* currentNode){
    Node *auxNodeA = currentNode->right;
    Node *auxNodeB = auxNodeA->left;

    auxNodeA->left = currentNode;
    currentNode->right = auxNodeB;

    currentNode->height = updateHeight(currentNode);
    auxNodeA->height = updateHeight(auxNodeA);

    return auxNodeA;
};

Node* rotateRight(Node* currentNode){
    Node *auxNodeA = currentNode->left;
    Node *auxNodeB = auxNodeA->right;

    auxNodeA->right = currentNode;
    currentNode->left = auxNodeB;

    currentNode->height = updateHeight(currentNode);
    auxNodeA->height = updateHeight(auxNodeA);

    return auxNodeA;
};

int updateHeight(Node* currentNode){
    if (currentNode->left == NULL || currentNode->right == NULL){
        return 0;
    };
    
    return ((currentNode->left->height > currentNode->right->height) ? currentNode->left->height : currentNode->right->height) + 1;
};