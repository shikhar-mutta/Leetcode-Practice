// Link: https://leetcode.com/problems/orderly-queue/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2) for k==1, O(n log n) for k>1  SC: O(n)
// Approach: if k>1, any two characters can be swapped (via move-to-back
// then move-back-to-front tricks), so the answer is just the sorted
// string. If k==1, only rotations are reachable, so try every rotation
// and return the lexicographically smallest.
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        string best = s;
        for (int i = 1; i < (int)s.size(); i++) {
            string rotated = s.substr(i) + s.substr(0, i);
            if (rotated < best) best = rotated;
        }
        return best;
    }
};
