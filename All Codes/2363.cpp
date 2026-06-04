// Link: https://leetcode.com/problems/merge-similar-items/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach: Hash Map. TC: O(nlohn) + O(mlogm) + O(klogk), SC: O(n + m + k)
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
    {
        unordered_map<int, int> mp;
        for (const auto &item : items1)
        {
            mp[item[0]] += item[1];
        }
        for (const auto &item : items2)
        {
            mp[item[0]] += item[1];
        }
        vector<vector<int>> result;
        for (const auto &pair : mp)
            result.push_back({pair.first, pair.second});

        sort(result.begin(), result.end());
        return result;
    }
};
