string minWindow(string s, string t) {
    unordered_map<char, int> need;
    for (auto c : t) {
        need[c]++;
    }
    cout << need.size() << endl;
    unordered_map<char, int> window;
    int left = 0;
    int right = 0;
    int valid = 0; // 辅助判断滑窗是否满足条件
    int min_l = INT_MAX;
    string ans;
    int start = 0;
    while (right < s.size()) {
        // s1: 构建窗口
        char c = s[right];
        right++;
        // 细节1
        if(need.count(c)) {
            window[c]++; // 加入滑窗
            if(window[c] == need[c]) // 某一元素满足条件
                valid++;
        }
        //printf( "1 window: [%d, %d)\n", left, right);
        // s2 : 更新滑窗数据， 更新结果
        // 细节2
        while (valid == need.size()) {
            if (right - left < min_l) {
                min_l = right - left;
                start = left;
            }
            char d = s[left];
            left++;
            // 移除辅助判断条件  更新当前滑窗状态；
            // 细节3  只有当target串中有该元素才处理
            if (need.count(d)) {
                if (window[d] == need[d]) {
                    valid--;
                }
                window[d]--;
            }
        }
        //printf( "2 window: [%d, %d)\n", left, right);

    }
    return min_l == INT_MAX ? "" : s.substr(start, min_l);
}