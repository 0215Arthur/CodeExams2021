/*
一个机器人要从起始点A和终点B。机器人从起点开始，每次能从上，下，左，右移动一步通过一个房间。并且每个房间只能路过一次。

设定机器人的健康数为H，如果经过的房间是正整数a，那么机器人经过这个房间就能获得对应的健康点数，健康数变成H+a，如果经过的房间为负数，那么机器人就会失去对应的健康点数a， 机器人的健康数变成H-a，问如果要保证机器人生命数一直是正数，H初始值至少为多少？

房间点数由一个二维数组M*N 表示，起点和终点由一个一维数组组成。

1 <= M,N <= 200

m == rooms.length

n == rooms[i].length

-1000 <= rooms[i][j] <= 1000

0 <= i,j <= M,N
*/

#include<iostream>
#include<vector>
using namespace std;

    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     * 
     * 
     * @param rooms int整型vector<vector<>> 房间
     * @param startPoint int整型vector 起始点
     * @param endPoint int整型vector 终点
     * @return int整型
     */
    
    int ans = INT_MIN;
    int dirs[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<int>> visited;
    bool dfs(vector<vector<int> >& rooms, vector<int>& start, vector<int>& end, vector<int>& path) {
        // cout << "s: "<< score << " "  << start[0] << " " << start[1] << endl;
        if (start[0] == end[0] && start[1] == end[1]) {
            // 到达终点s
            int curS = 0;
            for (auto p : path) {
                cout << p << " " ;
                curS = min(curS, p);
            }
            cout << endl;
            if (curS == 0) {
                return true;
            }
            // 取最大的负数
            ans = max(ans, curS);
            return false;
        }
        for (int i = 0; i < 4; i++) {
            int r = start[0];
            int c = start[1];
            int _row = start[0] + dirs[i][0];
            int _col = start[1] + dirs[i][1];
            if (_row < rooms.size() && _row >= 0 && _col < rooms[0].size() && _col >= 0) {
                if (visited[_row][_col] == 0) {
                    visited[_row][_col] = 1;
                    start[0] = _row;
                    start[1] = _col;
                    path.push_back(path.back() + rooms[_row][_col]);
                    if (dfs(rooms,start , end, path))
                        return true;
                    visited[_row][_col] = 0;
                    path.pop_back();
                    start[0] = r;
                    start[1] = c;
                }
            } 
        }
        return false;
    }
    int minimumInitHealth(vector<vector<int> >& rooms, vector<int>& startPoint, vector<int>& endPoint) {
        // write code here
        visited = vector<vector<int>> (rooms.size(), vector<int>(rooms[0].size()));
        visited[startPoint[0]][startPoint[1]] = 1;
        vector<int> path;
        path.push_back( rooms[startPoint[0]][startPoint[1]]);
        bool res = dfs(rooms, startPoint, endPoint,path);
        if (res) {
            return 1;
        }
        return -ans + 1; 
    }

int main() {
    vector<vector<int>> rooms= {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    vector<int> start = {0, 0};
    vector<int> end = {2, 2};
    
    minimumInitHealth(rooms, start, end);
    cout << "ans:" << ans << endl;
    return 0;
}




// class Solution {
// public:    
//     int ans = -2000;
//     int dirs[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
//     bool dfs(vector<vector<int>>& rooms, vector<int>& start, vector<int>& end, vector<int>& path, 
//         vector<vector<int>> & visited) {
//         // cout << "s: "<< score << " "  << start[0] << " " << start[1] << endl;
//         if (start[0] == end[0] && start[1] == end[1]) {
//             // 到达终点s
//             int curS = 0;
//             for (auto p : path) {
               
//                 curS = min(curS, p);
//             }
            
//             if (curS == 0) {
//                 return true;
//             }
//             // 取最大的负数
//             ans = max(ans, curS);
//             return false;
//         }
//         for (int i = 0; i < 4; i++) {
//             int r = start[0];
//             int c = start[1];
//             int _row = start[0] + dirs[i][0];
//             int _col = start[1] + dirs[i][1];
//             if (_row < rooms.size() && _row >= 0 && _col < rooms[0].size() && _col >= 0) {
//                 if (visited[_row][_col] == 0) {
//                     visited[_row][_col] = 1;
//                     start[0] = _row;
//                     start[1] = _col;
//                     path.push_back(path.back() + rooms[_row][_col]);
//                     if (dfs(rooms,start , end, path, visited))
//                         return true;
//                     visited[_row][_col] = 0;
//                     path.pop_back();
//                     start[0] = r;
//                     start[1] = c;
//                 }
//             } 
//         }
//         return false;
//     }
//     int minimumInitHealth(vector<vector<int>>& rooms, vector<int>& startPoint, vector<int>& endPoint) {
//         //return 1;
//         // write code here
//         vector<vector<int>> visited = vector<vector<int>> (rooms.size(), vector<int>(rooms[0].size()));
//         visited[startPoint[0]][startPoint[1]] = 1;
//         vector<int> path;
//         path.push_back( rooms[startPoint[0]][startPoint[1]]);
//         bool res = dfs(rooms, startPoint, endPoint,path, visited);
//         if (res) {
//             return 1;
//         }
//         return -ans + 1; 
//     }
// };
