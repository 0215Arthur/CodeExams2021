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


int main() {
    vector<int> nums;
    int target;
    cin >> target;
    int a;
    while (cin >> a) {
        nums.push_back(a);
    }
    cout << target << endl;
    //searchV0(nums, target);
    check(nums, 5, 3);
    int ans = findMaxLen(nums, target);
    cout << ans << endl;

    return 0;
}