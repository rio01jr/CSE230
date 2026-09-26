using namespace std;
#include <vector>

vector<long long> MERGE(vector<long long> left, vector<long long> right){
    vector<long long> result;
    int i = 0, j = 0;
    int leftSize = left.size();
    int rightSize = right.size();

    while(i < leftSize && j < rightSize){
        if (left.at(i) <= right.at(j)){
            result.push_back(left.at(i));
            i++;
        }
        else{
            result.push_back(right.at(j));
            j++;
        }
    }
    while(i < leftSize){
        result.push_back(left.at(i));
        i++;
    }
    while(j < rightSize){
        result.push_back(right.at(j));
        j++;
    }
    
    return result;
}

vector<long long> MERGE_SORT(vector<long long> arr){
    long long arrSize = arr.size();
    if(arrSize <= 1){
        return arr;
    }
    long long mid = arrSize / 2;
    vector<long long> Left = MERGE_SORT(vector<long long>(arr.begin(), arr.begin() + mid));
    vector<long long> Right = MERGE_SORT(vector<long long>(arr.begin() + mid, arr.end()));

    return MERGE(Left, Right);
}
