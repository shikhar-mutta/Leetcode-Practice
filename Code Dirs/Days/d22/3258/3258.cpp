// Link: https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size(), l = 0, zeros = 0, ones = 0, ans = 0;
        for (int r = 0; r < n; r++) {
            (s[r] == '0' ? zeros : ones)++;
            // shrink while window violates: too many 0s AND too many 1s
            while (zeros > k && ones > k)
                (s[l++] == '0' ? zeros : ones)--;
            ans += r - l + 1;            // all substrings ending at r with start in [l, r]
        }
        return ans;
    }
};
