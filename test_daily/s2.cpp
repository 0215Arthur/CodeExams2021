/*
> https://mp.weixin.qq.com/s/UFv7pt_djjZoK_gzUBrRXA
> 给定一个数组，要求选出一个区间, 使得该区间是所有区间中经过如下计算的值最大的一个：区间中的最小数 * 区间所有数的和。

```
输入
3
6 2 1
输出
36
解释：满足条件区间是[6] = 6 * 6 = 36;
```
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int N = 500000+10;
int a[N];
int dp[N];
int main() {
    stack<int> st;
    int n, res = 0;
    cin >> n;
    // 处理边界问题 前后加0
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n+1] = 0;

    // 计算前缀和 前置为0
    int pre = 0;
    for (int i = 0; i <= n + 1; i++) {
        dp[i] = pre + a[i];
        pre = dp[i];
    }
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && a[st.top()] > a[i]) {
            int peak = a[st.top()];
            st.pop();
            int left = a[st.top()];
            int lens = dp[i-1] - dp[left];
             
            res = max(res, lens*peak);
        }
        st.push(i);
    }
    cout << res << endl;
    return res;
}