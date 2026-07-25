// Link: https://leetcode.com/problems/range-frequency-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) for initialization, O(log n) for each query
// SC: O(n), where n is the length of the input array arr
// Approach:
// 1. We will create an unordered_map to store the indices of each value in the input array arr.
// 2. For each query, we will use lower_bound and upper_bound to find the range of indices for the given value within the specified left and right bounds.
// 3. Finally, we will return the count of indices within that range, which represents the frequency of the value in the specified range.
class RangeFreqQuery
{
public:
    unordered_map<int, vector<int>> mp;

    RangeFreqQuery(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value)
    {
        if (mp.find(value) == mp.end())
            return 0;

        vector<int> &v = mp[value];

        auto l = lower_bound(v.begin(), v.end(), left);
        auto r = upper_bound(v.begin(), v.end(), right);

        return r - l;
    }
};
