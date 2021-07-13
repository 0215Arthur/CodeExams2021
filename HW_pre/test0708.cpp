#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    string st;
    bool flag = false;
    for (auto p : s) {
        flag = false;
        while (!st.empty() && st.back() == p) {
            st.pop_back();
            flag = true;
        }
        if (!flag) st.push_back(p);
    }
    cout << st << endl;
    return 0;
}