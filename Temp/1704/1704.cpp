// Link: https://leetcode.com/problems/determine-if-string-halves-are-alike/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        string vowels = "aeiouAEIOU";
        int n = s.size();
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n / 2; i++) if (vowels.find(s[i]) != string::npos) cnt1++;
        for (int i = n / 2; i < n; i++) if (vowels.find(s[i]) != string::npos) cnt2++;
        return cnt1 == cnt2;
    }
};
