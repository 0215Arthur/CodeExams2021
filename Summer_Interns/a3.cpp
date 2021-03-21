#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<unordered_map>

using namespace std;
/*
时间复杂度： O(N!)
空间复杂度： O(N)
*/
bool isValid(unordered_map<int, int> & useCount, int interger) {
    unordered_map<int, int>::iterator  iter;
    //cout << " cur: "<< interger << endl;
    //cout << " state: ";
    for(iter = useCount.begin(); iter != useCount.end(); iter++) {
        if(iter -> second ==0)
            return false;
    }
     cout << " state: true" << endl;
     return true;
    
}
void backTrack(int interger, set<int>& finds, vector<int> keys, unordered_map<int, int> & useCount,  unordered_map<int, int> digits, int Len) {
    
    if (interger != 0 && isValid(useCount, interger) &&  to_string(interger).size() >= useCount.size() ) {
        finds.insert(interger);
    }
    //cout << interger << ":" << to_string(interger).size() << endl;
    if (to_string(interger).size() == Len)
        return;
    //int res = 0;
    
    for (int i = 0; i < keys.size(); i++) {
        if(useCount[keys[i]] < digits[keys[i]]) {
            int _next = interger*10 + keys[i];
            //cout << "next" << _next << endl;
            if (_next == 0) {
                continue;
            }
            useCount[keys[i]]++;
            for(unordered_map<int,int>::iterator iter = useCount.begin(); iter != useCount.end(); iter++){
                cout << iter -> first << iter -> second << endl; 
            }
            cout << " ---" << endl;
            backTrack(_next, finds, keys, useCount, digits, Len);
            useCount[keys[i]]--;
        }
    }
    //return res;
}

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> digits;
    unordered_map<int, int> useCount;
    while (n--) {
        int a;
        cin >> a;
        digits[a] ++;
        useCount[a] = 0;
    }
    vector<int> keys;
    set<int> finds;
    unordered_map<int, int>::iterator   iter;
     for(iter = digits.begin(); iter != digits.end(); iter++){
          keys.push_back(iter->first);
     }

    if (digits.count(0) && digits[0] == n) {
        cout << 0 << endl;
    } 
    backTrack(0, finds, keys, useCount,digits, n);
    //cout << "res"  << endl;
    cout << finds.size() << endl;
    // for(set<int>::iterator iter = finds.begin(); iter != finds.end(); iter++){
    //     cout << *iter<< endl;
    // }
    return 0;
}