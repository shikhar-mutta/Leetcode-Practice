// Link: https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n) for the output (positions can't exceed n+1)
// Approach: the true score at split i is (zeros in nums[0..i-1]) + (ones in
// nums[i..n-1]); tracking it as a running delta from an arbitrary baseline
// of 0 works fine since every split's score is offset by the same constant
// (total ones), so relative comparisons - and thus which splits are tied
// for max - are unaffected. Moving the split past nums[i] adds 1 if that
// element is a 0 (now correctly on the left) or subtracts 1 if it's a 1
// (now on the wrong side). Record every i whose score ties the best so far.
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();

        int high_score = -1;
        vector<int> positions;

        int score = 0;

        for (int i = 0; i < n + 1; i++) {

            if (score > high_score) {
                high_score = score;
                positions = {i};
            } else if (score == high_score) {
                positions.push_back(i);
            }

            if (i < n)
                score += (nums[i] == 0) ? 1 : -1;
        }

        return positions;
    }
};
