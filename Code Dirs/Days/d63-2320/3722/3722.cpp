// Link: https://leetcode.com/problems/lexicographically-smallest-string-after-reverse/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n)
// Approach: n is small, so just try every k for reversing the prefix and
// every k for reversing the suffix, tracking the lexicographically
// smallest result.
class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();
        string best = s;
        for (int k = 1; k <= n; k++) {
            string t = s;
            reverse(t.begin(), t.begin() + k);
            if (t < best) best = t;
        }
        for (int k = 1; k <= n; k++) {
            string t = s;
            reverse(t.end() - k, t.end());
            if (t < best) best = t;
        }
        return best;
    }
};
