#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void bubbleSort(vector<int>& arr) {
    int L = arr.size();
    for (int i = 0; i < L; i++) {
        bool flag = false;
        for (int j = 0; j < L - 1 -i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag  = true;
            }
        }
        cout << i << "th :";
        for (int k = 0; k < L; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
        if (!flag)
            break; 
    }
}

int main() {
        int a;
    vector<int > arr;
    while(cin >> a) {
        arr.push_back(a);
    }
    bubbleSort(arr);
    for (int i = 0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}