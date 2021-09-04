#include<iostream>
#include<vector>
using namespace std;

int main() {
    int k ,j;
    cin>> k >> j;
    vector<int> ans(k + 1);
    ans[0] = 1;
    for (int i = 1; i < k; i++) {
        ans[i] = 1;
        for (int j = i - 1; j > 0; j--) {
            ans[j] = ans[j - 1] + ans[j];
        }
    }
    cout << ans[j-1] << endl;
    return 0;
}
