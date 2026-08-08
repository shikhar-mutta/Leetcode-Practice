// Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> st;
        for (char c : s) {
            if (!st.empty() && st.back().first == c) {
                st.back().second++;
                if (st.back().second == k) st.pop_back();
            } else {
                st.push_back({c, 1});
            }
        }
        string res;
        for (auto& [c, cnt] : st) res += string(cnt, c);
        return res;
    }
};
