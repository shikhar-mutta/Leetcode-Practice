// Link: https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach: Greedy. TC: O(n), SC: O(1).
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
    {
        int requireEqp = 0, accExp = initialExperience;
        for (auto it : experience)
        {
            if (it >= accExp)
            {
                requireEqp += it - accExp + 1;
                accExp = (accExp + (it - accExp + 1)) + it;
                continue;
            }
            accExp += it;
        }
        // requireEng can goes minus that's why we take max with 0.
        int requireEng = max(0, accumulate(energy.begin(), energy.end(), 0) - initialEnergy + 1);
        return requireEqp + requireEng;
    }
};
