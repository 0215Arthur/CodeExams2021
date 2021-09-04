#include<iostream>
#include<queue>
#include<list>
using namespace std;

int main() {
    int n;
    cin >> n;
    list<int> h;
    int pre = -1;
    priority_queue<int, vector<int>, greater<int>> qp;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == pre) {
            continue;
        }
        pre = t;
        h.push_back(pre);
    }
    cout << "init" << endl;
    for (auto p : h) {
        qp.push(p);
        cout << p << " ";
    }
    cout << endl;
    pre = -1;
    vector<int> ans;
    while (!qp.empty()) {
        while (pre == qp.top() || qp.top() == 0) {
            qp.pop();
        }
        int cur = qp.top();
        pre = cur;
        int tmp = -1;
        for (list<int>::iterator it = h.begin(); it != h.end(); ) {
            //cout << "before : " << *it << " ";
            if (*it > 0) {
                if (*it < cur) {
                    *it = 0;
                }
                else {
                    *it -= cur;
                }
                //tmp == *it;
            }
            //cout << *it << endl;
            if (tmp == *it) {
                it = h.erase(it);
            }
            else {
                tmp = *it;
                it++;
            }
            //cout << "tmp: " << tmp << endl;
        }
        //cout << "size: " << h.size() << endl;
        ans.push_back(h.size());
        if (h.size() == 1) {
            break;
        }
    }
    cout << ans.size() << endl;
    for (auto p : ans) {
        cout << p << " ";
    }
    cout << endl;
    
    return 0;
}