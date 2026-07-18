// Link: https://leetcode.com/problems/relative-ranks/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();
        vector<string> ans(n);
        // Sort indices by score in descending order
        vector<int> idx(n);
        // Initialize indices by their original positions
        iota(idx.begin(), idx.end(), 0); // Fill idx with 0, 1, ..., n-1
        // Sort indices based on corresponding scores
        sort(idx.begin(), idx.end(), [&](int a, int b)
             { return score[a] > score[b]; });

        // Assign ranks based on sorted indices
        for (int rank = 0; rank < n; rank++)
        {
            if (rank == 0)
                ans[idx[rank]] = "Gold Medal";
            else if (rank == 1)
                ans[idx[rank]] = "Silver Medal";
            else if (rank == 2)
                ans[idx[rank]] = "Bronze Medal";
            else
                ans[idx[rank]] = to_string(rank + 1);
        }
        return ans;
    }
};