#include<iostream>
#include<vector>
#include <string>
using namespace std;

int main() {
    vector<int> nums(10);
    for (int i = 0; i < 10; i++) {
        cin >> nums[i];
    }
    string a;
    string b;
    for (int i = 9; i>= 0; i--) {
        if (nums[i] > 0) {
            int k = nums[i] / 2;
            cout << "k" << k << endl;
            for (int j = 0; j < k; j++) {
                a.push_back('0' + i);
            }
            for (int j = 0; j < nums[i] - k; j++) {
                b.push_back('0' + i);
            }
        }
    }
    cout << a << " " << b << endl;
    if (a.empty()) {
        cout << stoi(b) << endl;
    }
    else if (b.empty()) {
        cout << stoi(a) << endl;
    }
    else {
        cout << stol(a) * stol(b) << endl;
    }
    
    return 0;
}