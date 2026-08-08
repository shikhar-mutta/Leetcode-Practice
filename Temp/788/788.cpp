// Link: https://leetcode.com/problems/rotated-digits/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(1)
// Approach: for each number, check digits: any 3/4/7 disqualifies; at least one of 2/5/6/9 required to count as "different after rotation".
class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            int x = i;
            bool valid = true, changed = false;
            while (x > 0) {
                int d = x % 10;
                if (d == 3 || d == 4 || d == 7) { valid = false; break; }
                if (d == 2 || d == 5 || d == 6 || d == 9) changed = true;
                x /= 10;
            }
            if (valid && changed) count++;
        }
        return count;
    }
};
