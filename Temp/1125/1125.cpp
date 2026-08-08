// Link: https://leetcode.com/problems/smallest-sufficient-team/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        unordered_map<string,int> skillIdx;
        for (int i = 0; i < n; i++) skillIdx[req_skills[i]] = i;

        int m = people.size();
        vector<int> peopleMask(m, 0);
        for (int i = 0; i < m; i++)
            for (auto& s : people[i])
                if (skillIdx.count(s)) peopleMask[i] |= (1 << skillIdx[s]);

        int full = 1 << n;
        vector<long long> dp(full, -1);
        vector<int> parentMask(full, -1), parentPerson(full, -1);
        dp[0] = 0;
        for (int mask = 0; mask < full; mask++) {
            if (dp[mask] == -1) continue;
            for (int i = 0; i < m; i++) {
                int nmask = mask | peopleMask[i];
                if (nmask == mask) continue;
                long long cnt = dp[mask] + 1;
                if (dp[nmask] == -1 || cnt < dp[nmask]) {
                    dp[nmask] = cnt;
                    parentMask[nmask] = mask;
                    parentPerson[nmask] = i;
                }
            }
        }

        vector<int> res;
        int cur = full - 1;
        while (cur != 0) {
            res.push_back(parentPerson[cur]);
            cur = parentMask[cur];
        }
        return res;
    }
};
