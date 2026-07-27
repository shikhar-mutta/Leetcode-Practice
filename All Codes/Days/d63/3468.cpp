// Link: https://leetcode.com/problems/find-the-number-of-copy-arrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: copy[i] = original[i] + k for a single shared k, so k must
// lie in [bounds[i][0]-original[i], bounds[i][1]-original[i]] for every
// i. Intersect all those ranges; the answer is the size of the result.
class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int lo = INT_MIN, hi = INT_MAX;
        for (int i = 0; i < (int)original.size(); i++) {
            lo = max(lo, bounds[i][0] - original[i]);
            hi = min(hi, bounds[i][1] - original[i]);
        }
        return max(0, hi - lo + 1);
    }
};
