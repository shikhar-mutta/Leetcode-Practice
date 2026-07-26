// Link: https://leetcode.com/problems/lexicographically-smallest-string-after-operations-with-constraint/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: Greedily minimize each character left to right. The cyclic cost
// to turn char at idx to 'a' is min(idx, 26-idx); if the remaining budget k
// covers it, spend that and set to 'a'; otherwise spend all of k moving the
// character as close to 'a' as the budget allows and stop.
class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            int cost = min(idx, 26 - idx);
            if (k >= cost) {
                s[i] = 'a';
                k -= cost;
            } else {
                s[i] = 'a' + (idx - k);
                k = 0;
                break;
            }
        }
        return s;
    }
};
