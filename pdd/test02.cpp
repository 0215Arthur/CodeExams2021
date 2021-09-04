#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void check(string s) {
    int n = s.size();
    int i = 0;
    bool flag = false;
    string key;
    string val;
    while (i < n) {
        if (!flag && s[i] == ' ') {
            continue;
        }
        if (s[i] == '=') {
            
        }
        if (s[i] == '#') {
            break;
        }
    }

}

int main() {
    int N;
    cin >> N;
    while (N > 0) {
        string tmp;
        cin >> tmp;
        if (tmp.size() > 1) {
            N--;
        }
    }
    return 0;

}