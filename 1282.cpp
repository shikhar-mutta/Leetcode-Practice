// Link: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(n) where n is the size of the groupSizes vector
    //  Approach:
    //   1. We can use a hash map to store the indices of the people based on their group sizes. We can iterate through the groupSizes vector and for each person, we can add their index to the corresponding group size in the hash map.
    // 2.Once we have all the indices for a particular group size, we can create groups of that size and add them to the result vector. We can repeat this process for all group sizes in the hash map and return the result vector.
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        vector<vector<int>> result;
        unordered_map<int, vector<int>> freq;

        for (int i = 0; i < groupSizes.size(); i++)
        {
            freq[groupSizes[i]].push_back(i);
        }
        for (auto &[val, indices] : freq)
        {
            vector<int> group;
            for (auto idx : indices)
            {
                group.push_back(idx);

                if (group.size() == val)
                {
                    result.push_back(group);
                    group.clear();
                }
            }
        }
        return result;
    }
};