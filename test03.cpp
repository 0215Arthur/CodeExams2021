#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main() {
    string str;
    string target;
    int index = 0;
    cin >> str >> target;
    cin >> index;
    //cout << "test" << endl;
    unordered_map<char, vector<int> > idxs;
    for (int i = 0; i< str.size(); i++) {
        
        idxs[str[i]].push_back(i);
    }
    
    int Len = str.size();
    int ans = 0;
    for (int i = 0; i < target.size(); i++) {
        char cur = target[i];
        int next_index = 0;
        int min_step = 100000;
        for (int j =0; j < idxs[cur].size(); j++) {
            if (index == idxs[cur][j]) {
                min_step = 0;
                next_index = index;
                break;
            }
            if (index < idxs[cur][j]) //在左边
            {
                int right_dist = idxs[cur][j] - index;
                int left_dst = index + Len - idxs[cur][j];
                int tmp = min(right_dist, left_dst);
                if (tmp < min_step) {
                    next_index = idxs[cur][j];
                    min_step = tmp;
                }
            }
            else {
                int right_dist =  index - idxs[cur][j];
                int left_dst =  Len + idxs[cur][j] - index;
                int tmp = min(right_dist, left_dst);
                if (tmp < min_step) {
                    next_index = idxs[cur][j];
                    min_step = tmp;
                }
            }
        }
        index = next_index;
        //cout << min_step << " ";
        ans += min_step;
    }
    cout << ans << endl;
    return 0;
}