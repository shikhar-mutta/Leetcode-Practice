// Link: https://leetcode.com/problems/array-nesting/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) extra
// Approach: each index belongs to exactly one cycle; walk each unvisited
// cycle once, marking visited indices, track the longest cycle length
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        int best = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            int len = 0, j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = nums[j];
                len++;
            }
            best = max(best, len);
        }
        return best;
    }
};
