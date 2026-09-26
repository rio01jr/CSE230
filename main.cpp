using namespace std;
#include <iostream>
#include <vector>
#include "merge_sort.h"

int main() {
//cout << "enter an array of numbers" << endl;

vector<long long> arr;
long long num = 0;
//int index = 0;
cin >> num;
while(!cin.eof()){
    
    arr.push_back(num);
    cin >> num;
    //cout << "you entered: " << arr.at(index) << endl;
    //index++;
}

/*for(auto a : arr){
    cout << a << " ";
}
cout << endl;*/
arr = MERGE_SORT(arr);

for(auto a : arr){
    cout << a << " ";
}
cout << endl;

return 0;
}