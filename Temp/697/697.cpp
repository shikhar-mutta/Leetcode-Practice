// Link: https://leetcode.com/problems/degree-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: track first index, last index, and count for each value; find the max degree, then min (last-first+1) among values achieving that degree.
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> first, count;
        unordered_map<int,int> last;
        for (int i = 0; i < (int)nums.size(); i++) {
            int x = nums[i];
            if (!first.count(x)) first[x] = i;
            last[x] = i;
            count[x]++;
        }
        int maxDeg = 0;
        for (auto& [x, c] : count) maxDeg = max(maxDeg, c);
        int best = INT_MAX;
        for (auto& [x, c] : count) {
            if (c == maxDeg) best = min(best, last[x] - first[x] + 1);
        }
        return best;
    }
};
