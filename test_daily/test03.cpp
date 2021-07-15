#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long ans = 0;
    int n = s.size();
    int left = 0;
    int bcnt = 0;
    int acnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'b') {
            bcnt++;
        }
        else {
            acnt++;
            ans += bcnt % 1000000007;
            bcnt *= 2;
            bcnt %= 1000000007;
        }
    }
    cout << ans % 1000000007 << endl;
    return 0;
}
