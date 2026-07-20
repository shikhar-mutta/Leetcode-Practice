// Link: https://leetcode.com/problems/maximum-total-from-optimal-activation-order/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) SC: O(n)
    // Approach:
    //  1. Group the values based on their corresponding limits using an unordered_map.
    //  2. For each group, sort the values in descending order and take the minimum
    //     between the size of the group and the limit to calculate the total.
    //  3. Return the total sum of the selected values.
    long long maxTotal(vector<int> &value, vector<int> &limit)
    {
        int n = value.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++)
            groups[limit[i]].push_back(value[i]);
        long long total = 0;
        for (auto &[L, vals] : groups)
        {
            int take = min((int)vals.size(), L);
            sort(vals.rbegin(), vals.rend());
            for (int i = 0; i < take; i++)
                total += vals[i];
        }
        return total;
    }
};
