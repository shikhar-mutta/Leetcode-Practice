// Link: https://leetcode.com/problems/construct-k-palindrome-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if ((int)s.size() < k) return false;
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        int odd = 0;
        for (int i = 0; i < 26; i++) if (cnt[i] % 2 != 0) odd++;
        return odd <= k;
    }
};
