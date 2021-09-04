#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N;
    int T1, T2, T3, T4;
    cin >> N >> T1 >> T2 >> T3 >> T4;
    vector<vector<int>> paths(2, vector<int>(N));
    for (int i = 0; i < N; i++) {
        cin >> paths[0][i];
        paths[1][i] = 4 - paths[0][i];
    }
    vector<vector<int>> dps(2, vector<int>(N,1e9));
    dps[0][0] = 0;
    dps[1][0] = 0;
    for (int i = 1; i < N; i++) {
        for (int index = 0; index < 2; index++) {        
            if (paths[index][i] - paths[index][i - 1] > 1) {
                // 只能转换赛道
                int next = (index + 1) % 2;
                //if (dps[next][i-1] == )
                dps[next][i] = min(dps[next][i], dps[index][i - 1] + T4 + T2); 
            }
            else {
                int next = (index + 1) % 2;
                // if (dps[index][i-1] == 1e9) {
                //     dps[index][i-1] = dps[next][i-1] + T4;
                // }
                // 同赛道内转移
                if (paths[index][i] > paths[index][i - 1]) {
                    dps[index][i] = min(dps[index][i], dps[index][i-1] + T2);
                }
                else if (paths[index][i] == paths[index][i - 1]) {
                    dps[index][i] = min(dps[index][i], dps[index][i-1] + T1);
                }
                else if (paths[index][i] < paths[index][i - 1]) {
                    dps[index][i] = min(dps[index][i], dps[index][i-1] + T3);
                }
                // 可以在上一位置跳至平行赛道
                if (dps[index][i-1] + T4 < dps[next][i-1]) {
                    if (paths[next][i] > paths[next][i - 1] && paths[next][i] - paths[next][i - 1] == 1) {
                        dps[next][i] = min(dps[next][i], dps[index][i-1] + T4 + T2);
                    }
                    else if (paths[next][i] == paths[next][i - 1]) {
                        dps[next][i] = min(dps[next][i],dps[index][i-1] + T4  + T1);
                    }
                    else if (paths[next][i] < paths[next][i - 1]) {
                        dps[next][i] = min(dps[next][i], dps[index][i-1] + T4  + T3);
                    }
                }
            }
        }
    }
    cout << min(dps[0][N-1], dps[1][N-1]) << endl;

    return 0;
}