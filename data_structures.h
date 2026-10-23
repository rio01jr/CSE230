#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H


typedef struct TAG_ELEMENT{
    int index; //index of element
    double key; //key value of the element
    int pos; // index in heap-array, 0 if not in heap
}ELEMENT;

typedef struct TAG_HEAP{
    int size; //current size of the heap
    int capacity; //maximum size of the heap
    int *H; // array of pointers to indices of the ELEMENT array 
}HEAP;


#endif //DATA_STRUCTURES_H