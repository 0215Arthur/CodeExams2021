
// 
vector<vector<int>> resetZero(vector<vector<int>>& array) {
    unordered_set<int> rs;
    unordered_set<int> cs;
    int rows = array.size();
    int cols = array[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j  < cols; j++) {
            if (array[i][j] == 0) {
                rs.insert(i);
                cs.insert(j);
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (rs.find(i) != rs.end()) {
                array[i][j] = 0;
            }
            if (cs.find(j) != cs.end()) {
                array[i][j] = 0;
            }
        }
    }
    return array;
}