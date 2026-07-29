// Link: https://leetcode.com/problems/maximum-xor-score-subarray-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2 + Q), SC: O(N^2)
// Approach: the "XOR score" reduction score[i][j] (repeatedly XOR adjacent pairs until one value
// remains) satisfies score[i][j] = score[i][j-1] ^ score[i+1][j] for j>i, score[i][i]=nums[i].
// Precompute that table, then best[i][j] = max XOR score over any subarray within [i,j] via
// best[i][j] = max(score[i][j], best[i+1][j], best[i][j-1]), filled by increasing range length.
// Each query then answers in O(1).
class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> score(n, vector<int>(n, 0));
        vector<vector<int>> best(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) { score[i][i] = nums[i]; best[i][i] = nums[i]; }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                score[i][j] = score[i][j-1] ^ score[i+1][j];
                best[i][j] = max({score[i][j], best[i+1][j], best[i][j-1]});
            }
        }

        vector<int> ans;
        for (auto& q : queries) ans.push_back(best[q[0]][q[1]]);
        return ans;
    }
};
