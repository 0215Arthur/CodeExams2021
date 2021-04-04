#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
int rows = 0; 
int cols = 0;


void backTrack(vector<vector<int> > board, int row, int col, vector<vector<int> >& visited) {
    if (board[row][col] == )


    if (row + 1 < rows) backTrack(board,row+1,col,visited);
    if (col + 1 < rows) backTrack(board,row, col + 1,visited);
    if (row - 1 >=  0) backTrack(board,row - 1,col, visited);
    if (col - 1 >= 0) backTrack(board,row, col - 1,visited);

}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int> > board;
    vector<vector<int> > visited(n, vector<int>(n))
    while(n--) {
        int a;
        vector<int> tmp;
        while (n--)
        {
            cin >> a;
            tmp.push_back(a);
        }
        board.push_back(tmp);
    }
    for (int row =0; row <n ; row ++) {
        for (int col = 0; col < n; col++ ) {
            if (board[row][col] == 1) {

            }
        }
    }

    return 0;
}