// Link: https://leetcode.com/problems/longest-harmonious-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: count frequency of each value; for each value v present, if v+1 also present, candidate length is count[v]+count[v+1].
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for (int x : nums) cnt[x]++;
        int best = 0;
        for (auto& [v, c] : cnt) {
            if (cnt.count(v+1)) best = max(best, c + cnt[v+1]);
        }
        return best;
    }
};
