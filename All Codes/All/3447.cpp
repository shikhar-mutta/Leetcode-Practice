// Link: https://leetcode.com/problems/assign-elements-to-groups-with-constraints/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log m) SC: O(m)
//  Approach: for each element, mark all multiples of it as assignable to that element. Then for each group, return the index of the first element that can be assigned to it.
//  For example, if elements = [2,3] and groups = [6,9], then 6 can be assigned to 2 (index 0) and 9 can be assigned to 3 (index 1). If a group cannot be assigned to any element, return -1 for that group.
class Solution
{
public:
    vector<int> assignElements(vector<int> &groups, vector<int> &elements)
    {
        int maxGroup = *max_element(groups.begin(), groups.end());

        vector<int> divisors(maxGroup + 1, -1);

        for (int i = 0; i < elements.size(); ++i)
        {
            if (elements[i] > maxGroup)
                continue;
            if (divisors[elements[i]] != -1)
                continue;

            for (int d = elements[i]; d <= maxGroup; d += elements[i])
            {
                if (divisors[d] == -1)
                    divisors[d] = i;
            }
        }

        vector<int> result(groups.size());
        for (int i = 0; i < groups.size(); ++i)
        {
            result[i] = divisors[groups[i]];
        }
        return result;
    }
};