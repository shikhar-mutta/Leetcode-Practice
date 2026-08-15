// Link: https://leetcode.com/problems/self-dividing-numbers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((right-left)*log) SC: O(1) extra
// Approach: for each number, check each digit divides it evenly and no digit is zero.
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int n = left; n <= right; n++) {
            int x = n;
            bool ok = true;
            while (x > 0) {
                int d = x % 10;
                if (d == 0 || n % d != 0) { ok = false; break; }
                x /= 10;
            }
            if (ok) res.push_back(n);
        }
        return res;
    }
};
