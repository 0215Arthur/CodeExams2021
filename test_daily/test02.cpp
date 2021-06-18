/*
数轴上从左到右有n个点a[0],a[1]…,a[n-1]，
给定一根长度为L的绳子，求绳子最多能覆盖其中的几个点。
要求算法复杂度为o(n)， 空间复杂度为O(1)
*/

#include<iostream>
#include<vector>
using namespace std;


int maxPoints(vector<int>& nums, int len) {
    int ans = 0;
    int left = 0;
    int right = 0;
    while (right < nums.size()) {
        if ( (nums[right] - nums[left]) > len) {
            ans = max(ans, right - left);
            left++;
        }
        else {
            right++;
        }
        //cout << "l : " << left << " r :" << right << " " << ans << endl;
    }
    cout << ans << endl;
    return ans;
}


int main() {
    
    int len, n;
    cin >> len >> n;
    vector<int> nums;
    while(n--) {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    maxPoints(nums, len);
    return 0;
}