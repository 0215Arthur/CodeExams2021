#include<iostream>
#include<algorithm>
using namespace std;


string itos(int num) {
    string res = "";
    cout << "num" << num << endl;
    if (num == 0)
        return "0";
    while(num) {
        int a = num % 10;
        res.push_back((char)(a + '0'));
        num /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
void ftoa(float num) {
    bool flag = true;
    if (num < 0) {
        flag = false;
        num = -num;
    }
    int left = (int) num;
    float right = num - left;
    string res = "";
    string l = itos(left);
    if (!flag) {
        res.push_back('-');
    }
    res += l;

    cout << "target: "<< num << endl;
    // 无小数点
    if (right  > 0) {
        res.push_back('.');
        int count = 0;
        while( right - int(right) < 1 && right - int(right) > 0) {
            right *= 10;
            count++;
            cout << right  << endl;
        }
        
        string r = itos(int(right));
        while (count > r.size()) {
            res.push_back('0');
            count--;
        }
        res += r;
    }
    cout << res << endl;
}
int main() {
    float num;
    cin >> num;
    ftoa(num);
    return 0;
}