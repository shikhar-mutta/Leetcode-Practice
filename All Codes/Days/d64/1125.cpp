// Link: https://leetcode.com/problems/smallest-sufficient-team/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(people * 2^skills)  SC: O(2^skills)
// Approach: bitmask DP over covered-skill sets. dp[mask] stores the
// smallest list of person indices whose combined skills cover exactly
// `mask`. For each person, try adding them to every currently-reachable
// mask, updating dp[mask | personSkills] if it yields a smaller team
// (OR is idempotent, so revisiting states is safe without special
// iteration order). The answer is dp[fullMask].
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int k = req_skills.size();
        unordered_map<string,int> skillIdx;
        for (int i = 0; i < k; i++) skillIdx[req_skills[i]] = i;

        int n = people.size();
        vector<int> personMask(n, 0);
        for (int i = 0; i < n; i++)
            for (auto& sk : people[i])
                if (skillIdx.count(sk)) personMask[i] |= (1 << skillIdx[sk]);

        int full = 1 << k;
        vector<vector<int>> dp(full);
        vector<bool> reached(full, false);
        reached[0] = true;

        for (int p = 0; p < n; p++) {
            for (int mask = 0; mask < full; mask++) {
                if (!reached[mask]) continue;
                int nm = mask | personMask[p];
                if (nm == mask) continue;
                if (!reached[nm] || dp[mask].size() + 1 < dp[nm].size()) {
                    dp[nm] = dp[mask];
                    dp[nm].push_back(p);
                    reached[nm] = true;
                }
            }
        }
        return dp[full - 1];
    }
};
