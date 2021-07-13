#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

void searchV0(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();
    int mid = 0;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            cout << "find:"<< mid << endl;
            return;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else if (nums[mid] > target) {
            right = mid;
        }
    }
    cout << "l: " << left << " m:" << mid << " r: " << right << endl;
}

bool check(vector<int> arr, int k, int length) {
    int num = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        //cout << arr[i] << " ";
        if (arr[i] >= length)
            num += (arr[i]/length);
        //cout << num << " ";
    }
    //cout << endl;
    cout << "length: " << length << ' ' << num << endl;
    return num >= k;
}


int findMaxLen(vector<int> arr, int k) {
    int l = 1;
    int r = 1;
    for (int i = 0; i<arr.size(); i++) {
        r = max(r, arr[i]);
    }
    cout << l << ' ' << r << endl;
    while(l <= r) {
        int mid = l + (r - l) / 2; 
        cout << 'm' << mid << endl;
        cout << check(arr, k , mid ) << endl;
        if (check(arr, k, mid)) {
            l = mid + 1;
        }
        else {
            r= mid - 1;
        }
        cout << "l: " << l << " r :" << r  << endl;
    }
    return r;
}

//这个算法中，first是最终要返回的位置
int my_lower_bound(vector<int> array, int size, int key)
{
    int first = 0, middle;
    int half, len;
    len = size;

    while(len > 0) {
        half = len >> 1;
        middle = first + half;
        if(array[middle] < key) {     
            first = middle + 1;          
            len = len-half-1;       //在右边子序列中查找
        }
        else
            len = half;            //在左边子序列（包含middle）中查找
    }
    return first;
}

int lower_bound_v1(vector<int> array, int key) {
    int left = 0;
    int right = array.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (array[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return left;
}

int lower_bound_v2(vector<int> array, int key) {
    int left = 0;
    int right = array.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    vector<int> nums;
    int target;
    cin >> target;
    int a;
    while (cin >> a) {
        nums.push_back(a);
    }
    cout << "lower_bound_v1: " << endl;
    cout << lower_bound_v1(nums, target) << endl;
    cout << "lower_bound_v2: " << endl;
    cout << lower_bound_v2(nums, target) << endl;

    //cout << target << endl;
    // cout << my_lower_bound(nums, nums.size(), target) << endl; 
    //cout << *lower_bound(nums.begin(), nums.end(), target) << endl;
    //searchV0(nums, target);
    // check(nums, 5, 3);
    // int ans = findMaxLen(nums, target);
    // cout << ans << endl;

    return 0;
}