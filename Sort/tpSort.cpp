/*拓扑排序实现*/

#include<iostream>
#include<vector>
#include<list>
#include<stack>

using namespace std;

vector<list<int> > adj; // 图的邻接表
vector<int> inDegree; // 节点入度
stack<int> st; // 记录零入度的节点

// 构建图  统计节点入度
void creatGraph() {
    int n, m, v1,  v2;
    cin >> n >> m;
    // 初始化邻接表
    adj.assign(n, list<int>());
    inDegree.assign(n, 0);
    while(m -- ) {
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        inDegree[v2] ++;
    }
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0)
            st.push(i);
    }

}
// 拓扑排序
void tpSort() {
    int cur;
    vector<int> ans;
    while(!st.empty()) {
        cur = st.top();
        st.pop();
        ans.push_back(cur);// 记录当前出栈的节点
        for (list<int>::iterator iter = adj[cur].begin(); iter != adj[cur].end(); iter++) {
            inDegree[*iter]--;
            if (inDegree[*iter] == 0) 
                st.push(*iter);
        }
    }
    if (ans.size() != adj.size()) {
        cout << "图有环" << endl;
    }
    else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    creatGraph();
    tpSort();
    return 0;
}