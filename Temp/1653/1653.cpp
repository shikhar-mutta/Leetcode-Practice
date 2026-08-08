// Link: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int countB = 0, ans = 0;
        for (char c : s) {
            if (c == 'b') countB++;
            else ans = min(countB, ans + 1);
        }
        return ans;
    }
};
