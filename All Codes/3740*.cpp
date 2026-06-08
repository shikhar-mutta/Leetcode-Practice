// Link: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    int minimumDistance(vector<int> &nums)
    {
        unordered_map<int, pair<int, vector<int>>> mp;
        int i = 0;
        for (auto it : nums)
        {
            mp[it].first++;
            mp[it].second.push_back(i++);
        }
        int minDist = INT_MAX, ans = -1, dist;
        for (auto &[num, p] : mp)
        {
            if (p.first >= 3)
            {
                const auto &indices = p.second;
                int n = indices.size();
                for (int i = 0; i <= n - 3; i++)
                {
                    dist = 2 * (indices[i + 2] - indices[i]); // Distance
                    if (minDist > dist)
                    {
                        minDist = dist;
                        ans = num;
                    };
                }
            }
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
};
