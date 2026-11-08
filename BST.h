#ifndef BST_H
#define BST_H

typedef struct Node
{
    int key;
    struct Node* left;
    struct Node* right;
}Node;

void INSERT(Node** root, int key);
void DELETE(Node** root, int key);
bool SEARCH(Node** root, int key);
void INORDER(Node** root);
void PREORDER(Node** root);
void POSTORDER(Node** root);  
void LEVELORDER(Node** root);

#endif