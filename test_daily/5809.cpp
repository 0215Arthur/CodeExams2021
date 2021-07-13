/*
给你一个字符串 s ，返回 s 中 长度为 3 的不同回文子序列 的个数。

即便存在多种方法来构建相同的子序列，但相同的子序列只计数一次。

回文 是正着读和反着读一样的字符串。

子序列 是由原字符串删除其中部分字符（也可以不删除）且不改变剩余字符之间相对顺序形成的一个新字符串。

例如，"ace" 是 "abcde" 的一个子序列

*/


class Solution {
public:
    unordered_set<string> st;
    unordered_map<char, int> freq;
    unordered_map<char, int> before;
    void check(string s, int left) {
        int ans = 0;        
        for (int i = 0; i < 26; i++) {
            if (before.count('a' + i) && before['a'+i] > 0) {
              
              string a;
              a.push_back('a' + i);
              a.push_back(s[left+1]);
              if (st.count(a)) {
                 continue;
              }
                
                if (freq.count('a'+i) > 0 && freq['a'+i] > 0) {
                    //cout << a << endl;
                    st.insert(a);
                } 
            }      
        }
    }
    
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int ans = 0;
        for (auto p : s) {
            freq[p]++;   
        }
        unordered_map<char, unordered_set<char>> test;
        unordered_set<char> local;
        for (int i = 1; i < n - 1; i++) {
            local.insert(s[i-1]);
            if (test.count(s[i]) && test[s[i]].size() >= 26)
                continue;
            test[s[i]] = local;
            freq[s[i]]--;
            freq[s[i-1]]--;
            before[s[i-1]]++;
            
            check(s, i-1);
            freq[s[i]]++;
        }
        return st.size();

    }
};