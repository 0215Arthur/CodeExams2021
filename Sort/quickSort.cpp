#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// https://blog.csdn.net/qq_28584889/article/details/88136498
/*
当基准数选择最左边的数字时，那么就应该先从右边开始搜索；
当基准数选择最右边的数字时，那么就应该先从左边开始搜索。
(不论是从小到大排序还是从大到小排)

时间复杂度： O（NLogN）  最差的情况下退化为 O(N^2)
空间复杂度：  O(LogN) 主要是栈的深度

*/
int Parition( vector<int>& arr, int left, int right) {
    int pivot = arr[left];
    int start = left;
    while(left < right) {
        while(left < right && arr[right] >= pivot) {
            right--;
        }
        while (left < right && arr[left] <= pivot) {
            left++;
        }

        if (left < right) {
            swap(arr[left],arr[right]);
        }
    }
    swap(arr[start], arr[left]);
    return left;
}

void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;
    int p = Parition(arr,left,right);
    cout << p  << endl;
    quickSort(arr,left,p-1);
    quickSort(arr,p+1, right);
}