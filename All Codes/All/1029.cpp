// Link: https://leetcode.com/problems/two-city-scheduling/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) for sorting the costs array
    // SC: O(1) for in-place sorting
    // Approach:
    //   1. Sort the costs array based on the difference between the cost of sending a person to city A and city B.
    //   2. Send the first n people to city A and the remaining n people to city B.
    //   3. Calculate the total cost of sending the people to the two cities and return it.
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        sort(costs.begin(), costs.end(),
             [](const vector<int> &a, const vector<int> &b)
             { return a[0] - a[1] < b[0] - b[1]; });
        int n = costs.size() / 2, total = 0;
        for (int i = 0; i < 2 * n; i++)
            total += (i < n) ? costs[i][0] : costs[i][1];
        return total;
    }
};
