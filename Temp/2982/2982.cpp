// Link: https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        map<pair<char,int>, int> cnt;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            int runLen = j - i;
            for (int len = 1; len <= runLen; len++) {
                cnt[{s[i], len}] += runLen - len + 1;
            }
            i = j;
        }
        int ans = -1;
        for (auto& [key, c] : cnt) {
            if (c >= 3) ans = max(ans, key.second);
        }
        return ans;
    }
};
