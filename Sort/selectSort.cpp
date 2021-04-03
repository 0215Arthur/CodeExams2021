/*
选择排序
原理： 每次遍历选择最小的一个
- 时间复杂度： O(N^2)
- 空间复杂度:  O(1)
- 稳定性：  不稳定
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void selectSort(vector<int>& arr) {
    int Len = arr.size();
    for (int i = 0; i < Len; i++) {
        for (int j = i + 1; j < Len; j++) {
            if (arr[j] < arr[i]) {
                swap(arr[j], arr[i]);
            }
        }
    }
}


int main() {
    int a;
    vector<int > arr;
    while(cin >> a) {
        arr.push_back(a);
    }
    selectSort(arr);
    for (int i = 0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
