using namespace std;
#include <iostream>
#include <vector>
#include "merge_sort.h"

int main() {
//cout << "enter an array of numbers" << endl;
size_t size = 0;
cin >> size;
vector<long long> arr;
long long num = 0;
size_t index = 0;

while(index < size){
    cin >> num;
    
    arr.push_back(num);
    
    //cout << "you entered: " << arr.at(index) << endl;
    index++;
}
//cout << "size before: " << arr.size() << endl;
/*for(auto a : arr){
    cout << a << " ";
}
cout << endl;*/
arr = MERGE_SORT(arr);
//cout << "size after: " << arr.size() << endl;
//arr.pop_back();
for(const auto &a : arr){
    cout << a << " ";
}
cout << endl;

return 0;
}