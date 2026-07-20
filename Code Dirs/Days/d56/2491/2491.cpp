// Link: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn)
    // SC: O(1)
    //  Approach:
    //  1. Sort the skill vector
    //  2. Calculate the target skill level by adding the first and last elements of the sorted vector
    //  3. Iterate through the skill vector from both ends, checking if the sum of the two elements is equal to the target skill level
    //  4. If the sum is not equal to the target skill level, return -1
    //  5. If the sum is equal to the target skill level, add the product of the two elements to the total skill level
    //  6. Return the total skill level after iterating through the entire vector
    long long dividePlayers(vector<int> &skill)
    {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        long long target = (long long)skill[0] + skill[n - 1];
        long long total = 0;
        for (int i = 0, j = n - 1; i < j; i++, j--)
        {
            if (skill[i] + skill[j] != target)
                return -1;
            total += (long long)skill[i] * skill[j];
        }
        return total;
    }
};
