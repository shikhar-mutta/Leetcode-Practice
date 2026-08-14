// Link: https://leetcode.com/problems/minimum-moves-to-convert-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMoves(string s) {
        int n = s.size();
        int ans = 0;
        int i = 0;
        while (i < n) {
            if (s[i] == 'X') {
                ans++;
                i += 3;
            } else {
                i++;
            }
        }
        return ans;
    }
};
