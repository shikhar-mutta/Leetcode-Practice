// Link: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> best = {0, 0, 0};
        for (auto& t : triplets) {
            if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                best[0] = max(best[0], t[0]);
                best[1] = max(best[1], t[1]);
                best[2] = max(best[2], t[2]);
            }
        }
        return best == target;
    }
};
