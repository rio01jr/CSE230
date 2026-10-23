#include "util.h"
#include "heap.h"
#include "data_structures.h"
#include <iostream>

using namespace std;

void printArray(ELEMENT **V, int size){
    //check if the array is empty
    cout << "Instruction: PrintArray" << endl;
    if(V == NULL){
        cerr << "Error: arrray is NULL" << endl;
        return;
    }
    //if not empty write heap information to the console
    for(int i = 1; i <= size; i++){
// stdout index key pos
        
        printf("%d %lf %d\n", i, V[i]->key, V[i]->pos);
    }
}
void Stop(){
    cout << "Instruction: Stop" << endl;
}
void decreaseKey(ELEMENT **V, int index, double newKey, HEAP *pHeap)
{

    printf("Instruction: DecreaseKey %d %lf\n", index, newKey);

    if(index > pHeap->capacity || newKey > V[index]->key)
    {
        cerr << "Error: invalid call to DecreaseKey" << endl;
        return;
    }
    if(V[index]->pos == 0)
    {
        cerr << "Error: V[index] not in the heap" << endl;
        return;
    }

    V[index]->key = newKey;

    shiftUp(pHeap, V, V[index]->pos);


}
void insertIndex(ELEMENT **V, int index, HEAP *pHeap)
{

    printf("Instruction: Insert %d\n", index);
    if(index < 1 || index > pHeap->capacity)
    {
        cerr << "Error: index out of bounds" << endl;
        return;
    }
    if(V[index]->pos != 0)
    {
        cerr << "Error: V[index] already in the heap" << endl;
        return;
    }

    pHeap->size++;
    pHeap->H[pHeap->size] = index;
    V[index]->pos = pHeap->size;
    shiftUp(pHeap, V, pHeap->size);
    cout  << "Element V[" <<index << "] inserted into the heap" << endl;
}