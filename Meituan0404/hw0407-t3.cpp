

/* 题目3
v2 优化版
通过率： 94%*/

#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int rows;
int cols;
int ans = -1;
//priority_queue<int, vector<int>, less<int> > qt;
void backTrack(vector<vector<int> >& board, int row, int col, int res, int totalTime) {
    
    res +=board[row][col];
    if (res > totalTime) 
            return;
    if (row == rows - 1 && col == cols - 1) {
        ans = max(ans, res);
        return;
    }
    
    if (row + 1 < rows && col < cols) {
        backTrack(board, row + 1, col, res, totalTime);
    }
    
    if (col + 1 < cols && row < rows) {
        backTrack(board, row, col + 1, res, totalTime);
    }
    res-=board[row][col];
    return;
}

int main() {
    int t;
    cin >> rows >> cols  >> t;
    ans = -1;
    vector<vector<int> > board;
    for (int j = 0; j < rows; j++) {
        vector<int> tmp;   
        for (int i = 0; i < cols; i++){
            int a;
            cin >> a;
            tmp.push_back(a);
        }
        board.push_back(tmp);
    }
    int res = 0;
    backTrack(board, 0, 0, res, t);
    if (ans == -1)
        cout<< -1 << endl;
    else 
        cout << ans << endl;
    return 0;
}