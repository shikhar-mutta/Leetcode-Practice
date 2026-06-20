// Link: https://leetcode.com/problems/percentage-of-letter-in-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC:O(n) SC:O(1)
    int percentageLetter(string s, char letter) {
        // count occurrences, then floor(count * 100 / length)
        int cnt = count(s.begin(), s.end(), letter);
        return cnt * 100 / (int)s.size();
    }
};
