#include <iostream>
using namespace std;

void bubbleSort(int arr[], int elementCount){

for(int i = 0; i < elementCount; i++){
    for(int j = 0; j < elementCount - 1 - i; j++){
        if(arr[j] > arr[j + 1]){
            int tmp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = tmp;
        }
    }
}

}

int main(){

//get input from user
    //number of elements
int elementCount;
//cout << "Enter how many elements in the array: ";
cin >> elementCount;
//cout << endl;
int numArr[elementCount] = {0};



for(int i = 0; i < elementCount; i++){
    //cout << "enter a number in the array: ";
    cin >> numArr[i];
    
}

/*cout << "Your entered: ";
for(int i = 0; i < elementCount; i++){
    cout << numArr[i] << " ";
}
cout << endl;*/
bubbleSort(numArr, elementCount);
//cout << "The sorted array is: ";
for(int i = 0; i < elementCount; i++){
    cout << numArr[i] << " ";
}
cout << endl;

return 0;
}

