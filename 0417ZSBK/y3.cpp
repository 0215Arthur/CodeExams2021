#include <iostream>
#include<vector>
#include<map>
#include <utility>
#include<unordered_map>
#include<queue>

using namespace std;

priority_queue<int, vector<int>, less<int> >  qt;


int main() {
    int T;
    cin >> T;
    int N;
    while (T--) {
        cin >> N;
        unordered_map<int, int> ids;
        vector<pair<int,int> > records;
        int index = 0;
        while (N --) {
            int a, b;
            cin >> a >>b;
            if (ids.count(a)) {
                int oid_idx = ids[a];
                if (records[oid_idx].second  < b) {
                    records[oid_idx].second = b;
                }
            }
            else {
                records.push_back(make_pair(a, b));
                ids[a] = index;
            }
            index++;
        }
    }
}