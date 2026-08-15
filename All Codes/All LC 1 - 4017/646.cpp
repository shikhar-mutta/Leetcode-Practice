// Link: https://leetcode.com/problems/maximum-length-of-pair-chain/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(1)
// Approach: greedy interval scheduling — sort by end value, take a pair if its start exceeds the last chosen end.
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](auto& a, auto& b){ return a[1] < b[1]; });
        int count = 0;
        int lastEnd = INT_MIN;
        for (auto& p : pairs) {
            if (p[0] > lastEnd) {
                count++;
                lastEnd = p[1];
            }
        }
        return count;
    }
};
