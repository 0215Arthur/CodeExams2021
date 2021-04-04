#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

int ans = 0;

// void dfs(string& str, int index, string& path) {
//     ans++;

//     for (int i = index + 1; i < str.length(); i++) {
//         if (path.back() >= str[i]){
//             continue;
//         }
//         path.push_back(str[i]);
//         dfs(str, index + 1, path);
//         // path.pop_back();
//     }
// }

// void dfs(string& str, int index) {
//     ans++;
//     for (int i = index + 1; i < str.length(); i++) {
//         if (str[index] >= str[i]){
//             continue;
//         }
//         dfs(str, index + 1);
//         // path.pop_back();
//     }
   
// }

void dfs(string& str, int index, string& path) {
    ans++;
    for (int i = index; i < str.length(); i++) {
        if (!path.empty() && path.back() >= 0){
            continue;
        }
        path.push_back(str[i]);
        dfs(str, i + 1, path);
        path.pop_back();
        // path.pop_back();
    }
}
int main() {
    string str;
    cin >> str;
    string path;
    sort(str.begin(), str.end());
    //dfs(str,0, path);
    
    for (int i = str.size() - 1;  i >= 0; i++)
    {
        dfs(str,i, path);
        cout << ans << endl;
        path.clear();
    }
    cout << ans << endl;
    return 0;
}