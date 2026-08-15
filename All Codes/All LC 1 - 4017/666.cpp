// Link: https://leetcode.com/problems/path-sum-iv/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: each 3-digit number encodes (depth, position-in-level, value); store value by key depth*10+pos in a map, then DFS from root (depth1,pos1) summing root-to-leaf path values; a node is a leaf if neither child key exists.
class Solution {
public:
    int pathSum(vector<int>& nums) {
        unordered_map<int,int> val;
        for (int n : nums) {
            int depth = n / 100, pos = (n / 10) % 10, v = n % 10;
            val[depth*10 + pos] = v;
        }
        return dfs(1, 1, 0, val);
    }
    int dfs(int depth, int pos, int sumSoFar, unordered_map<int,int>& val) {
        int key = depth*10 + pos;
        sumSoFar += val[key];
        int leftKey = (depth+1)*10 + (2*pos-1);
        int rightKey = (depth+1)*10 + (2*pos);
        bool hasLeft = val.count(leftKey), hasRight = val.count(rightKey);
        if (!hasLeft && !hasRight) return sumSoFar;
        int total = 0;
        if (hasLeft) total += dfs(depth+1, 2*pos-1, sumSoFar, val);
        if (hasRight) total += dfs(depth+1, 2*pos, sumSoFar, val);
        return total;
    }
};
