
#include<iostream>
#include<vector>
using namespace std;


int jump(int m, vector<int> array) {
    int n = array.size();
    int maxPosition = 0;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (m  < 0) return -1;
        if (i <= pos) {
            continue;
        }
        if (array[i] > 0) {
            if (m - (i - pos) >= 0) {
                
                m -= (i - pos);
                m += array[i];
                pos = i;
            }
            else {
                if (pos + m >= n - 1) {
                    return m - (n - 1 - pos) + array[n-1];
                }
                pos += m;
                m = 0;
                m += array[pos];
            }
        } 
        cout << pos << " : " << m << endl;
    }
    return m;
}

int main() {
    int m = 5;
    vector<int> array = {1, 2, -3, 4, 5, 6};
    cout << jump(m, array);
    return 0;
}