// Link: https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    // Approach:
    //   1. We can calculate the total number of milestones and the maximum number of milestones
    //   2. If the maximum number of milestones is greater than the sum of the rest of the milestones plus one, then we can only work for 2 * rest + 1 weeks
    //   3. Otherwise, we can work for the total number of milestones weeks
    long long numberOfWeeks(vector<int> &milestones)
    {
        long long sum = 0, mx = 0;
        for (int x : milestones)
        {
            sum += x;
            mx = max(mx, (long long)x);
        }
        long long rest = sum - mx;
        if (mx > rest + 1)
            return 2 * rest + 1;
        return sum;
    }
};