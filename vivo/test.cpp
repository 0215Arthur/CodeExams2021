/*

vivo 0617 提前批

第三题：最短路径
题目描述：
图像从传感器到输出JPEG格式图片经过很多node处理，这些node构成一个图像处理的pipeline，其中的有些节点依赖于其他节点输出。A->B表示B的执行依赖于A。
假设每个node执行时间为A(t)，即node A需要执行t秒，没有依赖的node可以并行执行。编写一个方法输入一个有向无环图pipeline，输出执行完需要的最短时间。
输入：第一行输入node的执行时间，第二行输入node的依赖关系。
输出：最短时间。

*/

#include<iostream>
#include<vector>
#include<deque>
using namespace std;
// 拓扑排序

void topoSort(vector<int>& path, vector<int> indegree, vector<vector<int> > adj, vector<int> times) {
    deque<int> q;
    vector<int> timeCount(indegree.size()); //记录到当前节点的时长
    for (int i = 0; i < indegree.size(); i++) {
        if (indegree[i] == 0) {
            q.push_back(i);
            timeCount[i] = times[i]; // 

        }
    }
    vector<int> relations(indegree.size()); // 记录当前节点的上游依赖节点的最大时长
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        path.push_back(cur);
        for (int i = 0; i < adj[cur].size(); i++) {
            indegree[adj[cur][i]]--;
            relations[adj[cur][i]] = max(relations[adj[cur][i]], timeCount[cur]);
            if (indegree[adj[cur][i]] == 0) {
                q.push_back(adj[cur][i]);
                int curT = times[adj[cur][i]];
                timeCount[adj[cur][i]] = curT + relations[adj[cur][i]];
            }
        }
    }
    cout <<  "target res:" << timeCount.back() << endl;
}

int main() {
    int node;
    vector<int> Ts;
    vector<vector<int> > adj;
    
    while(cin >> node) {
        Ts.push_back(node);
        if (cin.get() == '\n') {
            break;
        }
    }
    cout << Ts.size() << endl;
    for (int i = 0; i < Ts.size(); i++) {
        cout << Ts[i] << " ";
    }
    cout << endl;
    vector<int> tmp;
    vector<int> indegree(Ts.size(), 0);
    while(cin >> node) {
        // cout << node << "- ";
        if (node > 0) {
            tmp.push_back(node-1);
            indegree[node-1]++;
        }
        // else {
        //     adj.push_back(tmp);
        //     tmp.clear();
        // }
        if (cin.get() == ';') {
            for (int i = 0; i < tmp.size(); i++) {
                cout << tmp[i] << " ";
            }
            cout << endl;
            adj.push_back(tmp);
            tmp.clear();
        }
    }
    adj.push_back(tmp);
    // cout << endl;
    // for (int i = 0; i < Ts.size(); i++) {
    //     cout << indegree[i] << " ";
    // }
    // cout << endl;

    // cout << "adj" << endl;
    // for (int i = 0; i < adj.size(); i++) {
    //     for (int j = 0; j  < adj[i].size(); j++) {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout  << endl;
    // }
    
    vector<int> path;
    
    topoSort(path, indegree, adj, Ts);

    cout << "拓扑排序结果： " << endl;
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    
  
    return 0;
    
    
}