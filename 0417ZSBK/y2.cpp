#include <iostream>
#include<vector>
#include<list>
#include<map>
using namespace std;


map<char,char> keys;

int check(string s, int N, int M) {
    string tmp = s;
    int min_lose = N;
    
    for (int i = 0; i < N; i ++) {
        //cout << "index: " << i <<  endl;
        int lose = 0;
        s = tmp;
        int t = M;
        int index  = i;
        while (true) {
            int next = (index + 1)%N;
            while(s[next] == 'o') {
                next = (next + 1)%N;
            }
            if (next == index) {
                break;
            }
            // lose 
            if ( keys[s[index]] == s[next] ) {
                s[index] = 'o';
                index = next;
                lose++;
            }
            else if (s[index] == s[next]) {
                index = next;
            }
            else if (s[index] ==  keys[s[next]]) {
                s[next] = 'o';
                lose++;
            }
            t--;
            if (t == 0 || lose + 1 == N) {
                min_lose = min(min_lose, lose);
                break;
            }       
        }
    }
    return N - min_lose;
}

int main() {
    keys['R']= 'C';
    keys['S'] = 'R';
    keys['C'] = 'S';
    int T, N, M;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        string s;
        cin >> s;
        cout << check(s, N, M) << endl;
    }
    return 0;
}