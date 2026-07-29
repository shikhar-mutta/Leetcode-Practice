// Link: https://leetcode.com/problems/cycle-length-queries-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(Q log(max node)), SC: O(1) extra
// Approach: implicit complete binary tree, parent of node v is v/2. Walk both a,b up to their
// LCA by repeatedly halving the deeper one; cycle length = steps taken + 1 (the added edge).
class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto& q : queries) {
            long long a = q[0], b = q[1];
            int steps = 0;
            while (a != b) {
                if (a > b) a /= 2; else b /= 2;
                steps++;
            }
            ans.push_back(steps + 1);
        }
        return ans;
    }
};
