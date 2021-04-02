#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
struct compare {
    bool operator()(const pair<char,int> a, const pair<char, int> b) {
        
        return a.second <= b.second;
    }
};
struct compare2 {
    bool operator()(const pair<char,int> a, const pair<char, int> b) {
        
        return a.second == b.second && a.first < b.first;
    }
};

int main() {
    string teams;
    string scores;
    map<char, int> ans;
    while(cin >> teams >> scores) {
        char s1 = scores[0];
        char s2 = scores[2];
        char t1 = teams[0];
        char t2 = teams[2];
        if (s1 > s2) {
            ans[t1] +=3;
        }
        else if (s1 == s2) {
            ans[t1] ++;
            ans[t2] ++;
        }
        else if (s1 < s2) {
            ans[t2] +=3;
        }
    }
    //sort(ans.begin(),ans.end());
    vector<pair<char,int>> res(ans.begin(), ans.end());
    
    sort(res.begin(),res.end(), compare());
    
    //sort(res.begin(),res.end(), compare2());
    for (int i = res.size() - 1;i >=  0; i--) {
        cout << res[i].first <<  " " << res[i].second;
        if (i > 0) {
            cout << ",";
        }
    }


    return 0;
}