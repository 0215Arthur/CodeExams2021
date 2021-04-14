#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


int find(string& s) {
    int N = s.size();
    unordered_map<int, int> delta; // 记录01差值对应的位置索引
    int count0 = 0;
    int count1 = 0; // 记录当前出现的1次数
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == '0') {
            count0++;
        }
        else {
            count1++;
        }
        int _d = count0 - count1;
        if (delta.count(_d)) {
            ans = max(ans, i - delta[_d]);
        }
        else {
            delta[_d] = i;
        }
    }
    return ans;
}
int main() {
    string s;
    cin >> s;
    cout << find(s) << endl;
    return 0;
}