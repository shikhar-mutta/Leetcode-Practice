// Link: https://leetcode.com/problems/relative-ranks/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
// Approach: sort indices by score descending, assign medals to top 3 and
// numeric ranks to the rest
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return score[a] > score[b]; });

        vector<string> res(n);
        for (int rank = 0; rank < n; rank++) {
            if (rank == 0) res[idx[rank]] = "Gold Medal";
            else if (rank == 1) res[idx[rank]] = "Silver Medal";
            else if (rank == 2) res[idx[rank]] = "Bronze Medal";
            else res[idx[rank]] = to_string(rank + 1);
        }
        return res;
    }
};
