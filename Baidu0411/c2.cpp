
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n = 123;
    double d = 1234.5678;

    cout.setf(ios::left|ios::fixed);
    cout.width(10);
    cout.fill('*');
    cout << n << ',' << d << endl;
    return 0;
}
// class D {
//     public:
//     D() {
//         cout << 'A';
//     }
//     ~D() {
//         cout << 'B';
//     }
//     D(int i): number(i) {
//         cout << 'C';
//     }
//     int number;
// };

// D show(D v) {
//     return v;
// }
// int main() {
//     D tmp = show(5);
//     return 0;
// }
// CBB