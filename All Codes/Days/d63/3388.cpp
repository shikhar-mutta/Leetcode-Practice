// Link: https://leetcode.com/problems/count-beautiful-splits-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n^2)
// Approach: precompute lcp[i][j] = length of the longest common prefix
// of the suffixes starting at i and j (lcp[i][j] = lcp[i+1][j+1]+1 when
// nums[i]==nums[j], else 0). For every split into 3 non-empty contiguous
// parts (boundaries i, j), it's beautiful if part1 is a prefix of part2
// (len1 <= len2 and lcp[0][i] >= len1) or part2 is a prefix of part3
// (len2 <= len3 and lcp[i][j] >= len2); count all such (i, j).
class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> lcp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
                if (nums[i] == nums[j]) lcp[i][j] = lcp[i+1][j+1] + 1;

        int count = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len1 = i, len2 = j - i, len3 = n - j;
                bool cond1 = (len1 <= len2) && (lcp[0][i] >= len1);
                bool cond2 = (len2 <= len3) && (lcp[i][j] >= len2);
                if (cond1 || cond2) count++;
            }
        }
        return count;
    }
};
