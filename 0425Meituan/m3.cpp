#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int N, l, r, k;
    cin >> N;
    while (N--) {
        cin >> l >> r >> k;
        k %=26;
        for (int i = l-1; i < r; i++) {
            if (s[i] - k <'a') {
                s[i] = 'a' + 26 - ('a' - (s[i] - k));
          
            }
            else {
                s[i] = s[i] -k;
            }
        }
    }
    cout << s << endl;
    return 0;
}