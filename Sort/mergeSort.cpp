#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// https://zhuanlan.zhihu.com/p/74820690
/*
归并排序  mergeSort

稳定排序
时间复杂度： 稳定在
当基准数选择最左边的数字时，那么就应该先从右边开始搜索；
当基准数选择最右边的数字时，那么就应该先从左边开始搜索。
(不论是从小到大排序还是从大到小排)

时间复杂度： O（NLogN）  最差的情况下退化为 O(N^2)
空间复杂度：  O(LogN) 主要是栈的深度

*/
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> tmp;
    int i = left;
    int j = mid + 1;
    while(i <= mid && j <= right) {
        if (arr[i] > arr[j]) {
            tmp.push_back(arr[j]);
            j++;
        }
        else {
            tmp.push_back(arr[i]);
            i++;
        }
    }
    // 把没有遍历完的部分继续进行遍历
    while (i<=mid) {
        tmp.push_back(arr[i]);
        i++;
    }
    while (j <= right) {
        tmp.push_back(arr[j]);
        j++;
    }
    for (int i = 0; i <tmp.size(); i++) {
        arr[left++] = tmp[i];
    }
    cout << "after merge: "; 
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


int main() {
    int a;
    vector<int > arr;
    while(cin >> a) {
        arr.push_back(a);
    }
    mergeSort(arr, 0 , arr.size()-1);
    for (int i = 0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}