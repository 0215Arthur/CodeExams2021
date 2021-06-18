#include<iostream>
using namespace std;

int main() {
    int t;
    int m;
    cin >> t >> m;
    long long a;
    while(t--) {
        
        //cin >> a;
        scanf("%lld",&a);
        
        	//cout << (char) (a / m  + 'A');
        
        printf("%c",(char) (a / m  + 'A'));
            
        
       // cout << a % m << endl; 
        printf("%d\n",a % m);
    }
    return 0;
}