// Atividade 08,Álgebra Linear

#define atividade "08"
#define nome "Savio de Carvalho Soares"
#define matricula "552882"

#include <iostream>

struct node
{
    int key;
    node *left;
    node *right;
};

node *insert(node *root, int key)
{
    // Insere um novo valor na árvore binária na qual faz a busca
    if (root == nullptr)
    {
        node *novoNode = new node;
        novoNode->key = key;
        novoNode->left = novoNode->right = nullptr;
        return novoNode;
    }
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

node *loadTree(int *u, int n)
{
    /*
monta árvore a partir
 da inseção consecutiva de chaves do vetor u.
*/
    node *raiz = nullptr;
    for (int i = 0; i < n; i++)
    {
        raiz = insert(raiz, u[i]);
    }
    return raiz;
}

void loadVec(node *root, int u[], int &i)
{
    /*
varre árvore enraizada em root  usando percurso em ordem simétrica e coloca cada chave visitada progressivamente em u  na ordem de visitação da árvore. u.
*/
    if (root == nullptr)
        return;
    loadVec(root->left, u, i);
    u[i++] = root->key;
    loadVec(root->right, u, i);
}