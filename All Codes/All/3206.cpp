// Link: https://leetcode.com/problems/alternating-groups-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int numberOfAlternatingGroups(vector<int> &colors)
    {
        int count = 0;
        int n = colors.size();

        for (int i = 1; i < n - 1; i++)
            if (colors[i] != colors[i + 1] && colors[i] != colors[i - 1])
                count++;

        // Reduce modulo operations by checking the first and last elements separately
        if (colors[0] != colors[1] && colors[0] != colors[n - 1])
            count++;
        if (colors[n - 1] != colors[0] && colors[n - 1] != colors[n - 2])
            count++;

        return count;
    }
};
