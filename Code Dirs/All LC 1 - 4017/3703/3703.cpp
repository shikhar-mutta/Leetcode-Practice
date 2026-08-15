// Link: https://leetcode.com/problems/remove-k-balanced-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeSubstring(string s, int k) {
        vector<pair<char, long long>> st;
        for (char c : s) {
            if (!st.empty() && st.back().first == c) st.back().second++;
            else st.push_back({c, 1});

            while (st.size() >= 2) {
                int idx = st.size() - 1;
                int idx2 = idx - 1;
                if (st[idx2].first == '(' && st[idx].first == ')' &&
                    st[idx2].second >= k && st[idx].second >= k) {
                    st[idx].second -= k;
                    st[idx2].second -= k;
                    if (st[idx].second == 0) st.pop_back();
                    if (!st.empty() && st.back().second == 0) st.pop_back();
                } else break;
            }
        }

        string res;
        for (auto& [ch, cnt] : st) res += string(cnt, ch);
        return res;
    }
};
