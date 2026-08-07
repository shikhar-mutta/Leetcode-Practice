// Link: https://leetcode.com/problems/reconstruct-original-digits-from-english/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: count letters, extract digits with a uniquely-identifying
// letter first (z=0, w=2, u=4, x=6, g=8), then digits identifiable after
// removing those (h=8 used up ->3, f=5(4 used)->5, s=6(7)->7, then 1,9,0's leftover)
class Solution {
public:
    string originalDigits(string s) {
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;

        int digits[10] = {0};
        digits[0] = count['z' - 'a'];
        digits[2] = count['w' - 'a'];
        digits[4] = count['u' - 'a'];
        digits[6] = count['x' - 'a'];
        digits[8] = count['g' - 'a'];

        digits[3] = count['h' - 'a'] - digits[8];
        digits[5] = count['f' - 'a'] - digits[4];
        digits[7] = count['s' - 'a'] - digits[6];

        digits[1] = count['o' - 'a'] - digits[0] - digits[2] - digits[4];
        digits[9] = count['i' - 'a'] - digits[5] - digits[6] - digits[8];

        string res;
        for (int d = 0; d <= 9; d++) {
            for (int k = 0; k < digits[d]; k++) res += char('0' + d);
        }
        return res;
    }
};
