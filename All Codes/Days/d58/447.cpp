// Link: https://leetcode.com/problems/number-of-boomerangs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2)
    // SC: O(n)
    // Approach:
    //  1. For each point, calculate the distance to all other points and store the counts of each distance in a hash map.
    //  2. For each distance with count c, the number of boomerangs is c * (c - 1) because we can choose two points in c * (c - 1) ways.
    //  3. Sum up the boomerangs for all points and return the total.
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int n = points.size();
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<long long, int> distCount;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                long long dx = points[i][0] - points[j][0];
                long long dy = points[i][1] - points[j][1];
                distCount[dx * dx + dy * dy]++;
            }
            for (auto &[d, c] : distCount)
                total += c * (c - 1);
        }
        return total;
    }
};
