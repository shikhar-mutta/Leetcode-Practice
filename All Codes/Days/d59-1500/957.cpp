// Link: https://leetcode.com/problems/prison-cells-after-n-days/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    // Approach: Simulation + Cycle Detection
    vector<int> prisonAfterNDays(vector<int> &cells, int n)
    {
        vector<int> temp(8);
        temp[0] = 0;
        temp[7] = 0;
        vector<vector<int>> seen;
        int k = 0;

        while (n--)
        {
            for (int i = 1; i <= 6; i++)
            {
                temp[i] = (cells[i - 1] == cells[i + 1]);
            }
            if (seen.size() && seen.front() == temp)
                return seen[n % k];
            else
                seen.push_back(temp);
            cells = temp;
            k++;
        }

        return cells;
    }
};