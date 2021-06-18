#include<iostream>
using namespace std;
int b[100005];
int c[100005];

int main() {
    int t;
    cin >> t;
    int a;
    bool flag = true;
    int left = 0;
    int right = 0;
    while (t--) {
        cin >> a;
        flag = true;
        for (int i = 0; i < a; i++){
            scanf("%d", b + i);
            if (b[i] != (i + 1)) {
                flag = false;
                c[i] = 0;
            }
            else {
                c[i] = 1;
            }
        }
        if (flag) {
            cout << 0 << endl;
            continue;
        }
        bool order = true;

        int index = 0;
        bool noplan = false;
        for(int i = 0; i < a; i++)
            cout << c[i] << " ";
        cout << endl;

         while (index < a) {
            if (order)
                left = index;
            while (order && index < a && !c[index]) {
               // cout << index << " " << c[index] << endl;
                index++;
            }
            if (order)
                right = index;
            if (left != right) order = false;
            if (!order && index < a &&!c[index]) {
                noplan = true;
                break;
            }
            index++;
        }
        cout << left << right << endl;
        bool check = true;
        if (noplan) {
            for (int i = 0; i < a; i++) {
                if(b[i] != a - i)
                    check = false;
            }
            if (!check)  {
                printf("-1\n");
                continue;
            }
        }
       
        if (check && noplan) {
            printf("%d %d %d\n", 1, a, a - 1);
            continue;
        }
        if (abs(b[right] - b[left]) )
        printf("%d %d %d\n", left + 1, right, right - b[right - 1] );

    }
    return 0;
}