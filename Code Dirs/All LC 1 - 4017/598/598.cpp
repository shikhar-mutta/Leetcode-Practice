// Link: https://leetcode.com/problems/range-addition-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k) SC: O(1)
// Approach: max count area is bounded by the intersection rectangle of all ops (min a, min b), since every op covers [0,a)x[0,b) from origin.
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (auto& op : ops) { m = min(m, op[0]); n = min(n, op[1]); }
        return m * n;
    }
};
