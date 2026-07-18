// Link: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n), SC: O(n)
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        map<int, int> mergedMap;
        for (const auto &pair : nums1)
            mergedMap[pair[0]] += pair[1];

        for (const auto &pair : nums2)
            mergedMap[pair[0]] += pair[1];

        vector<vector<int>> result;
        for (const auto &entry : mergedMap)
            result.push_back({entry.first, entry.second});

        return result;
    }
};
