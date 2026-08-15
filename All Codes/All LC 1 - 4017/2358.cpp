// Link: https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach:
//  1. The maximum number of groups that can be formed is determined by the sum of the first k natural numbers, which is given by the formula k*(k+1)/2.
//  2. We need to find the largest integer k such that k*(k+1)/2 <= n, where n is the number of grades.
//  3. We can use a simple loop to increment k until the condition is no longer satisfied.
//  4. Return the value of k as the maximum number of groups that can be formed.
class Solution
{
public:
    int maximumGroups(vector<int> &grades)
    {
        int n = grades.size();
        int k = 0;
        while ((long long)(k + 1) * (k + 2) / 2 <= n)
            ++k;
        return k;
    }
};