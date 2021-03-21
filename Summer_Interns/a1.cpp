#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> times;
    while(n--) {
        int t;
        cin >> t;
        times.push_back(t);
    }
    vector<int> ans;
    vector<int> cost;
    vector<int> timeCount;
    int timeSum = 0; // 已消耗时间
    int timeFlag = 0; // 计时起点
    int curState = 0; // 计费状态
    int cost100 = 0;
    int line100 = 0;
    int line1000 = 0;
    int maxTime = times.back();
    for (int i = 0; i < n; i++) {
        if (cost.empty()){
            cost.push_back(20);
            ans.push_back(20);
            timeCount.push_back(times[i]);
            cost100 += 20;
            continue;
        }
        if (times[i] - line100 < 100) {
            if (cost100<=20){
                 ans.push_back(20);
                cost100 += 20;
                cost.push_back(cost.back()+20);
            }
            else{
                ans.push_back(50 - cost100);
                cost.push_back(cost.back()+50 - cost100);
            }       
        }
        else {
            line100 = times[i];
            ans.push_back(20);
            cost.push_back(cost.back()+20);
        }
    }
    
}
