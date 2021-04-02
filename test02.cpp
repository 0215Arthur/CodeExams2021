#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

int main() {
    vector<int> info;
    char t;
    cin >> t;
    int a;
    while(cin >> a) {
        info.push_back(a);
        if (cin.get() == ']')
             break;
    }
    set<int> ans;
    unordered_map<int,int> test;
    for(int i=0; i < info.size(); i++) {
        //cout << info[i] << endl;
        //ans.insert(info[i]+1);
        test[info[i]+1]++;
    }
    int res = 0;
    for (unordered_map<int,int> ::iterator iter = test.begin(); iter!=test.end(); iter++) {
        if (iter -> first ==1 ) {
            res += iter->second;
        }
        else {
               if (iter->second <= iter->first) {
                res += iter->first;
            }
            else {
                int s = int (iter->second / iter -> first) + 1;
                res += iter-> first * 2;
                } 
        }

    }
    //for(set<int>::iterator iter = ans.begin(); iter != ans.end(); iter++) {
    //    res += *iter;
    //}
    cout << res << endl;
    return 0;
}