/*
所谓回文数就是一个数字，从左边读和从右边读的结果都是一样的，例如12321。

现在有一个只包含1、2、3、4的数字，你可以通过在任意位置增加一位数字或者删除一位数字来将其变换成一个回文数。但是增加或删除不同数字所需要的代价是不一样的。

已知增加和删除每个数字的代价如下：

增加一个1，代价：100；删除一个1，代价：120。

增加一个2，代价：200；删除一个2，代价：350。

增加一个3，代价：360；删除一个3，代价：200。

增加一个4，代价：220；删除一个4，代价：320。

请问如何通过最少的代价将一个数字变换为一个回文数。当然，如果一个数字本身已经是一个回文数（包括一位数，例如：2），那么变换的代价为0。
*/

/*
样例输入
12322
样例输出
300
提示 增加一个1并增加一个2，将输入正整数变为1223221或者2123212，所需代价最小，为：100+200=300。
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int add[4] = {100, 200, 360, 220};
int del[4] = {120, 350, 200, 320};
vector<vector<int>> dp;
int dfs(string nums, int i, int j) {
    if (i >= j) return 0;
    if (dp[i][j] != 0) {
        return dp[i][j];
    }
    if (nums[i] == nums[j]) {
        dp[i][j] = dfs(nums, i + 1, j - 1);
    }
    else {
        dp[i][j] = min(min(dfs(nums, i + 1, j) + add[nums[i] - '1'], //添加左侧
                       dfs(nums, i, j - 1) + add[nums[j] - '1'] // 添加右侧
                      ),
                   min(dfs(nums, i + 1, j) + del[nums[i] - '1'], //删除左侧
                       dfs(nums, i, j - 1) + del[nums[j] - '1'] // 删除右侧
                      )
                      );
    }
    return dp[i][j];
}
int main() {
    string n;
    cin >> n;
    
    int N = n.size();
    dp = vector<vector<int>> (N, vector<int>(N));
     
    cout << dfs(n, 0, N - 1);
    return 0;
}