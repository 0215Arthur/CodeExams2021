#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int L = arr.size();
    for (int i = 0; i <  L; i++) {
        bool flag = false;
        for (int j = 0; j < L - i - 1; j++) {
            swap(arr[j], arr[j+1]);
            flag = true;
        }
        if (!flag)
            break;
    }
    return;
}
/* 稳定排序
时间复杂度 O(n^2) 空间复杂度 O(1)
最差情况 O(n^2) 最好情况： O(n)
*/
void insertSort(vector<int>& arr) {
    int L = arr.size();
    for (int i = 0; i < L - 1; i++) {
        int cur = arr[i + 1];
        int prev = i;
        while ( cur < arr[prev] && prev >= 0) {
            arr[prev + 1] = arr[prev]; // 后移
            prev--;
        }
        // 移动到目标值
        arr[prev+1] = cur;
    }
    return;
}

/*
时间复杂度 O(nlogn) 空间复杂度 O(1)
最差情况 O(nlogn) 最好情况： O(n)
*/
void shellSort(vector<int>& arr) {
    int  L = arr.size();
    int gap = L/2;
    while(gap) {
        for (int i = gap; i < L; i++) {
            int cur = arr[i];
            int prev = i - gap;
            // 设置移动间隔，即插入间隔
            while (prev >= 0 && cur < arr[prev]) {
                arr[prev] = cur;
                prev -= gap;
            }
            arr[prev + gap] = cur;
        }
        gap /= 2;
    }
}

/* 选择排序  非稳定排序
时间复杂度 O(n^2) 空间复杂度 O(1)
最差： O(N^2) 最好： O(N^2)
*/
void selectSort(vector<int>& arr) {
    int  L = arr.size(); 
    for (int i = 0; i < L - 1; i++) {
        for (int j = i + 1; j < L; j++) {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
    return;
}

/* 快速排序  非稳定排序
时间复杂度 O(nlogn) 空间复杂度 O(logn)
最差： O(N^2) 最好： O(nlogn)
*/

int Partition(vector<int>& arr, int left, int right) {
    int start = left;
    int pivot = arr[start];
    while(left < right) {
        while(left < right && arr[right] >= pivot) {
            right--;
        }
        while(left < right && arr[left] <= pivot) {
            left++;
        }
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }
    swap(arr[start], arr[left]);
    return left;
}

void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;
    int p = Partition(arr, left, right);
    quickSort(arr, left, p - 1);
    quickSort(arr, p + 1, right);
    return;
}

/* 归并排序  稳定排序
时间复杂度 O(n^2) 空间复杂度 O(n)
最差： O(nlogn) 最好： O(nlogn)

分治思想，自底而上，后序遍历； 
*/
void merge(vector<int>& arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    vector<int> tmp;
    while (i <= mid && j <= right) {
        if (arr[i] > arr[j]) {
            tmp.push_back(arr[j]); 
            j++;
        }
        else {
            tmp.push_back(arr[i]);
            i++;
        }
    }
    while (i <= mid) {
        tmp.push_back(arr[i]);
        i++;
    }
    while (j <= right) {
        tmp.push_back(arr[j]);
        j++;
    }
    for (int i = 0; i < tmp.size(); i++) {
        arr[i + left] = tmp[i];
    }
    return;
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) 
        return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
    return;
}



/* 堆排序  非稳定排序
时间复杂度 O(nlogn) 空间复杂度 O(1)
最差： O(nlogn) 最好： O(nlogn)
*/
void adjustHeap(vector<int>& arr, int length, int index) {
    int maxIdx = index;
    if (index* 2 + 1 < length && arr[2*index + 1] > arr[maxIdx]) maxIdx = 2*index + 1;
    if (index* 2 + 2 < length && arr[2*index + 2] > arr[maxIdx]) maxIdx = 2*index + 2;
    if (maxIdx != index) {
        swap(arr[maxIdx], arr[index]);
        adjustHeap(arr, length, maxIdx);
    }
}

void heapSort(vector<int>& arr) {
    int  L = arr.size(); 
    for (int i = L/2 - 1; i >= 0; i--) {
        adjustHeap(arr, L, i);
    }
    for (int i = L - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        adjustHeap(arr, i, 0);
    }
    return;
}