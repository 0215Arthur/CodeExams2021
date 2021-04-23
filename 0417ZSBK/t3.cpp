#include <iostream>
#include<math.h>
using namespace std;

int main() {
    float R;
    cin >> R;
    float x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    float a = pow((x1 - x2)* (x1 - x2) +(y1 - y2)* (y1 - y2), 0.5);
    // cout << a << endl; 1 1 0 1.6 0
    float res =  (a + R) / 2;
    float x3 = 0;
    float y3 = 0;
    float ratio = res / a;
    cout << "R" <<res << "a" << a << endl; 
    if (x1 == x2) {
        x3 = x2;
    }
    else {
        if (x1 > x2)  {
            x3 = x2 + (x1 - x2)*ratio;
            cout << x3 << endl;
        }
        else {
            x3 = x2 - (x2 - x1)*ratio;
        }
    }
    if (y1 == y2) {
        y3 = y1;
    }
    else {
        if (y1 > y2) {
            y3 = y2 + (y1 - y2)*ratio;
        }
        else {
            y3 = y2 - (y2 - y1)*ratio;
        }
    }
    cout << x3 << " " << y3 << " " << res << endl;
    return 0;
}


