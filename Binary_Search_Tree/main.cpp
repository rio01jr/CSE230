#include <iostream>
#include <string>
#include "BST.h"
using namespace std;

int main()
{
    // the first input is an int containing the number of queries
    int number_of_queries;
    cout << "Enter the number of queries: ";
    cin >> number_of_queries;

    //the next inputs are the queries
    string query;

    //declare variable used for insert and delete queries
    int key;

    //Initialize root of binary tree to a nullptr(empty tree)
    Node* root = new Node();
    root = nullptr; 
    

    //loop thhrough each query, stopping when i reaches the number of queries
    int i = 0;
    while(i < number_of_queries)
    {
        cin >> query;

        //check query to see what type of function to call
        if(query == "INSERT")
        {
            cin >> key;
            INSERT(&root, key);
        }
        else if(query == "DELETE")
        {
            cin >> key;
            DELETE(&root, key);
        }
        else if(query == "SEARCH")
        {
            cin >> key;
            
            if(SEARCH(&root, key))
            {
                cout << "True" << endl;
            }
            else
            {
                cout << "False" << endl;
            }
        }
        else if(query == "INORDER")
        {
            INORDER(&root);
            cout << endl;
        }
        else if(query == "PREORDER")
        {
            PREORDER(&root);
            cout << endl;
        }
        else if(query == "POSTORDER")
        {
            POSTORDER(&root);
            cout << endl;
        }
        else if(query == "LEVELORDER")
        {
            LEVELORDER(&root);
            cout << endl;
        }
        else
        {
            cout << "Error: Invalid query/instruction" << endl;
        }

    }

    return 0;
}