// Link: https://leetcode.com/problems/equal-score-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool scoreBalance(string s) {
        // letter score: a=1 .. z=26
        long long total = 0;
        for (char ch : s) total += ch - 'a' + 1;
        if (total % 2) return false;            // odd total can't split equally

        long long prefix = 0;
        // try every split point; both parts must be non-empty
        for (int i = 0; i + 1 < (int)s.size(); i++) {
            prefix += s[i] - 'a' + 1;
            if (prefix == total - prefix) return true;
        }
        return false;
    }
};
