#include <iostream>
#include "data_structures.h"
#include "heap.h"
#include "util.h"
#include <fstream>
#include <string>
#include <cstdio>

using namespace std; 
bool read(const char *inputFile, ELEMENT **&V, HEAP *&pHeap);
void Write(const char *outputFile, ELEMENT **V, int n);

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        cerr << "Usage: ./PJ3 <I-File> <O-File>\n" << "<I-File> is the input file\n" << "<O-File> is the output file" << endl;
        return 0;
    }
    /*int size = atoi(argv[1]);

    ELEMENT **V = new ELEMENT*[size + 1]; // pointer to a pointer to ELEMENT
    HEAP *pHeap = new HEAP; // pointer to a HEAP
    
    pHeap->size = size;
    pHeap->H = new int[size + 1]; */

//initialize array of elements v and heap array H with index and key values   
    /*for(int i = 1; i <= size; i++)
        {
        V[i] = new ELEMENT;
        V[i]->index = i;
        V[i]->key = atoi(argv[i + 1]);
        //cout << "key: " << V[i]->key << endl;
        V[i]->pos = 0;
        pHeap->H[i] = i;
    }*/
    //printArray(V, 0);
    
    //int arr[10] = {'\0'};
    
    //cout << "size of array: " << size << endl;
    
    /*buildHeap(pHeap, V);
    printHeap(pHeap, V);
    printArray(V, size);
    extractMin(pHeap, V);
    printHeap(pHeap, V);
    decreaseKey(V, 3, -4895, pHeap);
    printHeap(pHeap, V);*/
    ELEMENT **V = NULL;
    HEAP *pHeap = NULL;

    string instruction;

    while(cin >> instruction)
    {
        if(instruction == "Read")
        {
            if(!read(argv[1], V, pHeap))
            {
                continue;
            }
        }
        else if(instruction == "PrintArray")
        {
            printArray(V, pHeap->capacity);
        }
        else if(instruction == "PrintHeap")
        {
            printHeap(pHeap, V);
        }
        else if(instruction == "BuildHeap")
        {
            buildHeap(pHeap, V);
        }
        else if(instruction == "Write")
        {
            Write(argv[2], V, pHeap->capacity);
        }
        else if(instruction == "Stop")
        {
            Stop();
            break;
        }
        else if(instruction == "DecreaseKey")
        {
            int index;
            double newKey;
            cin >> index >> newKey;

            decreaseKey(V, index, newKey, pHeap);
        }
        else if(instruction == "ExtractMin")
        {
            extractMin(pHeap, V);
        }
        else if(instruction == "InsertIndex")
        {
            int index;
            double key;
            cin >> index >> key;
            if(!key)
            {
                UnknownInstructions();
                return;
            }
            insertIndex(V, index, key, pHeap);
        }
        else{
            UnknownInstructions();
        }
    }
    return 0;
}
void UnknownInstructions()
{
    cout << "Warning: Invalid Instruction" << endl;
}
bool read(const char *inputFile, ELEMENT **&V, HEAP *&pHeap)
{
    cout << "Instruction: Read" << endl;
    
    ifstream file(inputFile);

    if(!file.is_open())
    {
        cerr << "Error: could not open file" << endl;
        return false;
    }

    int n;
    file >> n;

    V = new ELEMENT*[n+1];

    for(int i = 1; i <= n; i++)
    {
        double key;
        file >> key;
        V[i] = new ELEMENT;
        V[i]->index = i;
        V[i]->key = key;
        V[i]->pos = 0;
    }
    file.close();

    pHeap = new HEAP;
    pHeap->capacity = n;
    pHeap->size = 0;
    pHeap->H = new int[n + 1];
    for(int i = 1; i <= n; i++)
    {
        pHeap->H[i] = i;
    }
    return true;
}

void Write(const char *outputFile, ELEMENT **V, int n)
{
    cout << "Instruction: Write" << endl;

    FILE *file = fopen(outputFile, "w");

    if(file == NULL)
    {
        cerr << "Error: could not open file" << endl;
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        fprintf(file, "%d %lf %d\n", i, V[i]->key, V[i]->pos);
    }

    fclose(file);
}