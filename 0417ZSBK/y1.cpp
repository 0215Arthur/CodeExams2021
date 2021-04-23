#include <iostream>
#include<vector>
using namespace std;

int plan1[3][3] = {{0,1,3},{0,2,1},{1,2,3}};// 双人
int plan2[3][3] = {{3,4,5},{3,5,4},{4,5,3}}; // 女双
vector<vector<int> > planA; 
vector<vector<int> > planB; 

void getPlans() {
    
    for (int i = 0; i < 3; i++) {
        // 男双
        for ( int j = 0; j < 3; j++) {
            vector<int> s;
            s.push_back(plan1[i][0]);
            s.push_back(plan1[i][1]);
            s.push_back(plan2[j][0]);
            s.push_back(plan2[j][1]);
            s.push_back(plan1[i][2]);
            s.push_back(plan2[j][2]);
            planA.push_back(s);
            planB.push_back(s);
            //s.clear();
        }
    }
    // cout << planA.size() << endl;
    // cout << planA[0].size() << endl;
    // for (int i = 0; i < 9; i++) {
    //     for (int j =0; j < 6; j++) {
    //         cout << planA[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}

int find(vector<int> A, vector<int> B) {
    int ans = 0;
    for ( int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int flag = 0;
            for (int k = 0; k < 3; k++) {
                int cost1 = A[planA[i][k*2]] + A[planA[i][k*2+1]];
                int cost2 = B[planB[j][k*2]] + B[planB[j][k*2+1]];
                if (cost1 < cost2) {
                    flag++;
                }
                //cout << "test" << endl;
            }
            if (flag >= 2) 
                ans++;
        }
    }
    return ans;
}

int main () {
    int T;
    cin >> T;
    getPlans();
    while (T--) {
        vector<int> A;
        for (int i = 0; i< 6; i++) {
            int a;
            cin >> a;
            A.push_back(a);
        }
        vector<int> B;
        for (int i = 0; i< 6; i++) {
            int b;
            cin >> b;
            B.push_back(b);
        }
        //cout << A[0] << ' ' << B[0] << endl;
        cout << find(A,B) << endl;
    }
    return 0;
}