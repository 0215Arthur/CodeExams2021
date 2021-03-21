#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>

using namespace std;

int main() {
    int N;
    cout << "please input ..." << endl;
    cin >> N;
    while (N--) {
        int a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    
    return 0;
}