// Link: https://leetcode.com/problems/grumpy-bookstore-owner/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of customers array
    // SC: O(1)
    // Approach:
    //  1. We can iterate through the customers array and calculate the base satisfaction by adding the number of customers that are not grumpy.
    //  2. We can then use a sliding window of size minutes to calculate the maximum extra satisfaction that can be obtained by using the technique to make the owner not grumpy for that window.
    //  3. We can then return the sum of the base satisfaction and the maximum extra satisfaction.
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = customers.size();
        int base = 0;
        for (int i = 0; i < n; i++)
            if (!grumpy[i])
                base += customers[i];

        int windowExtra = 0, bestExtra = 0;
        for (int i = 0; i < n; i++)
        {
            if (grumpy[i])
                windowExtra += customers[i];
            if (i >= minutes && grumpy[i - minutes])
                windowExtra -= customers[i - minutes];
            bestExtra = max(bestExtra, windowExtra);
        }
        return base + bestExtra;
    }
};
