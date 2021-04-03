/*
希尔排序
原理： 简单插入排序的升级， 通过设置插入间隔进行分组插入
- 时间复杂度： O(N^2)  最好的情况： O(N) 最差的情况： O(N^2)
- 空间复杂度:  O(1)
- 稳定性： 稳定 (不存在位置交换)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void shellSort(vector<int>& arr) {
    int Len = arr.size();
    int gap = Len/2;
    while (gap>0) {
        for (int i = gap; i < Len; i++) {
            int cur = arr[i];
            int prev = i - gap;
            while ( cur < arr[prev] && prev>=0) {
                arr[prev + gap] = arr[prev];
                prev-=gap;
            }
            arr[prev+gap] =  cur;
        }
        gap/=2;
    }
}


int main() {
    int a;
    vector<int > arr;
    while(cin >> a) {
        arr.push_back(a);
    }
    shellSort(arr);
    for (int i = 0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
