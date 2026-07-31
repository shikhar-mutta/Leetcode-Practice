// Link: https://leetcode.com/problems/smallest-sufficient-team/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(people * 2^skills)  SC: O(2^skills)
// Approach: bitmask DP over covered-skill sets. dp[mask] stores the smallest list of person indices whose combined skills cover exactly `mask`. For each person, try adding them to every currently-reachable mask, updating dp[mask | personSkills] if it yields a smaller team (OR is idempotent, so revisiting states is safe without special iteration order). The answer is dp[fullMask]. 
class Solution
{
public:
    vector<int> ans;
    vector<int> curr;
    vector<int> people_masks;
    vector<int> dp;
    unordered_map<string, int> skill_mp;
    int n;
    int m;

    void solve(int mask)
    {
        if (!ans.empty() && curr.size() >= ans.size())
        {
            return;
        }

        if (mask == (1 << n) - 1)
        {
            ans = curr;
            return;
        }

        if (curr.size() >= dp[mask])
        {
            return;
        }

        dp[mask] = curr.size();

        int missing_skill = 0;
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) == 0)
            {
                missing_skill = i;
                break;
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (people_masks[i] & (1 << missing_skill))
            {

                curr.push_back(i);
                solve(mask | people_masks[i]);
                curr.pop_back();
            }
        }
    }

    vector<int> smallestSufficientTeam(vector<string> &req_skills,
                                       vector<vector<string>> &people)
    {
        n = req_skills.size();
        m = people.size();

        skill_mp.clear();
        ans.clear();
        curr.clear();
        dp.assign(1 << n, INT_MAX);
        people_masks.assign(m, 0);

        for (int i = 0; i < n; i++)
        {
            skill_mp[req_skills[i]] = i;
        }

        for (int i = 0; i < m; i++)
        {
            for (const string &skill : people[i])
            {
                if (skill_mp.count(skill))
                {
                    int bit_index = skill_mp[skill];
                    people_masks[i] |= (1 << bit_index);
                }
            }
        }

        solve(0);

        return ans;
    }
};