#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


/*
给定一个乱序的栈，设计算法将其升序排列。

ps: 允许额外使用一个栈来辅助操作 

*/

stack<int> stackSort(stack<int> &stk) {
    stack<int> res;
    if (stk.empty()) return stk;
    while (! stk.empty()) {
        int cur = stk.top();
        stk.pop();
        while (!res.empty() && res.top() > cur) {
            stk.push(res.top());
            res.pop();
        }
        res.push(cur);
    }
    return res;
}

int main() {
    int N;
    stack<int> inp;
    cin >> N;
    cout << N << endl;
    while (N--) {
        int a;
        cin >> a;
        inp.push(a);
    }
    
    stack<int> res = stackSort(inp);
    while (!res.empty()) {
        cout << res.top() << " "; 
        res.pop();
    }
    cout << endl;
    return 0;
}