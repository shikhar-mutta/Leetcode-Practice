// Link: https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = count(nums.begin(), nums.end(), 1);
        int zeros = 0, ones = totalOnes;
        vector<int> scores(n + 1);
        scores[0] = ones; // split at 0: all zeros left(none)+all ones right
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) zeros++;
            else ones--;
            scores[i + 1] = zeros + ones;
        }
        int best = *max_element(scores.begin(), scores.end());
        vector<int> res;
        for (int i = 0; i <= n; i++) if (scores[i] == best) res.push_back(i);
        return res;
    }
};
