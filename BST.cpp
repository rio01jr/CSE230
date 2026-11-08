#include "BST.h"
#include <iostream>
#include <queue>
using namespace std;

void INSERT(Node** root, int key)
{
   if((*root) == nullptr) //check if root is NULL, if so create new node and assign it to root pointer
   {
        *root = new Node(); //create a new node and assign it to the root pointer
        (*root)->key = key; //assign given key to new node
        (*root)->left = nullptr; //assign left child to nullptr
        (*root)->right = nullptr; //assign right child to nullptr
   }
   else
   {
    if(key < (*root)->key) //if key is less than current node key, go to left child
    {
        INSERT(&(*root)->left, key); 
    }
    else if(key > (*root)->key) //if key is greater than current node key, go to right child
    {
        INSERT(&(*root)->right, key);
    }
   }
}
void DELETE(Node** root, int key)
{
    if(!SEARCH(root, key))
    {
        cout << "Key not found" << endl;
        return;
    }
    if(key < (*root)->key)
    {
        DELETE(&(*root)->left, key);
    }
    else if(key > (*root)->key)
    {
        DELETE(&(*root)->right, key);
    }
    else if((*root)->key == key)
    {
        if((*root)->left == nullptr && (*root)->right == nullptr) //if node has no children, delete node, no need to reassign
        {
            delete *root;
            *root = nullptr;
            return;
        }
        else if((*root)->left == nullptr && (*root)->right != nullptr) //if only right child exists, delete node and assign root = right child
        {
            Node* temp = *root;
            *root = (*root)->right;
            delete temp;
            return;
        }
        else if((*root)->right == nullptr && (*root)->left != nullptr) //if only left child exists, delete node and assign root = left child
        {
            Node* temp = *root;
            *root = (*root)->left;
            delete temp;
            return;
        }
        else if((*root)->left != nullptr && (*root)->right != nullptr) //if both children, find successor, assign successor key, delete successor node
        {
            Node * successor = (*root)->right; //find successor node(smallest node in right subtree)
            while(successor->left != nullptr)//while the successor has a left child, continue traversing left
            {
                successor = successor->left; //set successor = smallest node in right subtree
            }
            (*root)->key = successor->key; //assign current node key = successor key
            DELETE(&(*root)->right, successor->key); //delete the successor node from right subtree
        }
    }

}

bool SEARCH(Node** root, int key)
{
    if(*root == nullptr) //if root is a nullptr, return false(key not found)
    {
        return false;
    }
    else if((*root)->key == key) //if key is equal to current node key, return true(key found)
    {
        return true;
    }
    else if(key < (*root)->key) //if the key is less than current node key, use search on right child
    {
        return SEARCH(&(*root)->left, key);
    }
    else
    {
        return SEARCH(&(*root)->right, key); //if the key is greater than current node key, use search on left child
    }

}
void INORDER(Node** root)
{
    if(*root != nullptr)
    {
        INORDER(&(*root)->left);
        cout << (*root)->key << " ";
        INORDER(&(*root)->right);
    }
}

void PREORDER(Node** root)
{
    if(*root != nullptr)
    {
        cout << (*root)->key << " ";
        PREORDER(&(*root)->left);
        PREORDER(&(*root)->right);
    }
}

void POSTORDER(Node** root)
{
    if(*root != nullptr)
    {
        POSTORDER(&(*root)->left);
        POSTORDER(&(*root)->right);
        cout << (*root)->key << " ";
    }   
}
void LEVELORDER(Node** root)
{
    if(*root !=nullptr)
    {
        queue<Node*> q; //create a queue that hold pointers to nodes   
        q.push(*root); //push root node into queue
        while(!q.empty())//while queue is not empty
        {
            Node* currNode = q.front(); //get node at front of queue
            q.pop(); //remove node from front of queue
            cout << currNode->key << " "; //output key of the current node
            if(currNode->left != nullptr)
            {
                q.push(currNode->left); //push left child of the current node onto queue
            }
            if(currNode->right != nullptr)
            {
                q.push(currNode->right); //push right child of the current node onto queue
            }
        }
    }
}