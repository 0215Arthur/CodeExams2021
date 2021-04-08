/*

*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main( ) {
    int T;
    int n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> times;
        while (n--) {
            int t;
            cin >> t;
            times.push_back(t);
        }
        int ans = 0;
        sort(times.begin(), times.end());
        int left = 0;
        int right = times.size() - 1;
        
        while (left + 1 < right) {
            ans +=  times[left + 1];
            left += 2;
            ans +=  times[right];
            right -= 2;
        }
        cout << ans << endl;
    }

    return 0;
}