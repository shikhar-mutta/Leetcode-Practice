// Link: https://leetcode.com/problems/top-k-frequent-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn). SC: O(n).
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (int x : nums)
            freq[x]++;

        vector<pair<int, int>> items(freq.begin(), freq.end());
        // Highest frequency first; break ties by smaller value for stable output.
        sort(items.begin(), items.end(), [](const auto &a, const auto &b)
             { return a.second != b.second ? a.second > b.second : a.first < b.first; });

        vector<int> res;
        for (int i = 0; i < k && i < (int)items.size(); i++)
            res.push_back(items[i].first);
        return res;
    }
};
