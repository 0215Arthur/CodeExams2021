/*
插入排序
原理： 构建有序数组，每次往前面构成的有序数组中插入
- 时间复杂度： O(N^2)  最好的情况： O(N) 最差的情况： O(N^2)
- 空间复杂度:  O(1)
- 稳定性： 稳定 (不存在位置交换)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void insertSort(vector<int>& arr) {
    int Len = arr.size();
    for (int i = 0; i < Len - 1; i++) {
        int prev = i;
        int cur = arr[i+1];
        while (cur < arr[prev] && prev >= 0) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = cur;
    }
}


int main() {
    int a;
    vector<int > arr;
    while(cin >> a) {
        arr.push_back(a);
    }
    insertSort(arr);
    for (int i = 0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
