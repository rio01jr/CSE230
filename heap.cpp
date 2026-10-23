
#include "heap.h"
#include "data_structures.h"
#include <iostream>
#include <cstdio>
#include <utility>
#include <cmath>

using namespace std;

void buildHeap(HEAP *pHeap, ELEMENT **V)
{   
    if(pHeap->size == 0)
    {
    pHeap->size = pHeap->capacity;
    }

    cout << "Instruction: BuildHeap" << endl;
    for(int i = 1; i <= pHeap->size; i++)
    {
        pHeap->H[i] = i;
        V[i]->pos = i;
    }
    for(int i = floor(pHeap->size / 2); i >= 1; i--)
    {
        minHeapify(pHeap, V, i);
    }
    //pHeap->capacity = pHeap->size;

}

void minHeapify(HEAP *pHeap, ELEMENT **V, int i){

    int n = pHeap->size;
    int *H = pHeap->H;
    while (true) 
    {
        int left = 2 * i; // left child index
        int right = 2 * i + 1; // right child index
        int min = i;
//check for smallest among left, right, and node i
        //left
        if(left <= n && V[H[left]]->key < V[H[min]]->key)
        {
            min = left;
        }
        
        //right
        if(right <= n && V[H[right]]->key < V[H[min]]->key)
        {
            min = right;
        }

        //check if heap is finished
        if(min == i)
        {
            break; //heap is finished
        }
//swap the elements in heap
        /*int temp = H[i];
        H[i] = H[max];
        H[max] = temp;*/
        swap(H[i], H[min]);
         //continue loop until heap is finished

        V[H[i]]->pos = i;
        V[H[min]]->pos = min;
        i = min;

    }
}
void shiftUp(HEAP *pHeap, ELEMENT **V, int i)
{

    int *H = pHeap->H;
    while(i > 1 && V[H[i]]->key < V[H[i / 2]]->key)
    {
        swap(H[i], H[i / 2]);
        V[H[i]]->pos = i;
        V[H[i / 2]]->pos = i / 2;
        i /= 2;
    }

}

void printHeap(HEAP *pHeap, ELEMENT **V){
    cout << "Instruction: PrintHeap" << endl;
    //int size = 0;
    
    
    // check if the heap is NULL
    if(pHeap == NULL || V == NULL)
    {
    cerr << "Error: heap is NULL" << endl;
    return;
    }
    if(pHeap->size == 0)
    {
        cout << "Capacity = " << pHeap->capacity << ", "
        << "size = " << pHeap->size << endl;
        return;
    }
        
//get current size of the heap by counting elements in the heap array
        /*for(int i = 1; i <= pHeap->size; i++)
        {
            int index = pHeap->H[i];
            if(V[index] != NULL)
            {
             size++;  
            }
        }*/
    cout << "Capacity = " << pHeap->capacity << ", "
    << "size = " << pHeap->size << endl;

    for(int i = 1; i <= pHeap->size; i++)
    {
        int index = pHeap->H[i];
        cout << "H[" << i << "] = " << pHeap->H[i] << endl;
            
    }
}
void extractMin(HEAP *pHeap, ELEMENT **V)
{
    cout << "Instruction: ExtractMin" << endl;

    if(pHeap->size == 0 )
    {
        cerr << "Error: heap is NULL" << endl;
        return;
    }

    if(V == NULL || pHeap == NULL)
    {
        cerr << "Error: heap is empty" << endl;
        return;
    }
    int root = pHeap->H[1];
    V[root]->pos = 0;
    pHeap->H[1] = pHeap->H[pHeap->size];
    pHeap->size--;
    if(pHeap->size > 0)
    {
        V[pHeap->H[1]]->pos = 1;
        minHeapify(pHeap, V, 1);
    }

}
