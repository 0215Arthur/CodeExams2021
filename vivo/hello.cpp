#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int a;
    vector<int> nums;
    while (N--) {
        cin >> a;
        nums.push_back(a);
    }
    for (auto p : nums) {
        cout << p << endl;
    }

    printf("Hello World\n");
    system("pause");
    
    return 0;
}