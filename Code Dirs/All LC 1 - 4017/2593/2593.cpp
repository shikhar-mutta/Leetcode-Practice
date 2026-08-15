// Link: https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (nums[a] != nums[b]) return nums[a] < nums[b];
            return a < b;
        });

        vector<bool> marked(n, false);
        long long score = 0;
        for (int i : idx) {
            if (marked[i]) continue;
            score += nums[i];
            marked[i] = true;
            if (i > 0) marked[i-1] = true;
            if (i < n-1) marked[i+1] = true;
        }
        return score;
    }
};
