// Link: https://leetcode.com/problems/maximum-ice-cream-bars/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m) where n is the number of ice cream bars and m is the maximum cost of an ice cream bar.
    // SC: O(m) where m is the maximum cost of an ice cream bar.
    // Approach:
    //  1. Find the maximum cost of an ice cream bar in the costs vector.
    //  2. Create a frequency vector freq of size r + 1, where r is the maximum cost of an ice cream bar. Initialize all elements to 0.
    //  3. Iterate through the costs vector and increment the corresponding index in the freq vector for each cost.
    //  4. Initialize a counter c to 0 and a variable l to 1.
    //  5. While l is less than or equal to r and coins is greater than 0, do the following:
    //     a. While l is less than or equal to r and freq[l] is 0, increment l.
    //     b. If l is greater than r, break the loop.
    //     c. If coins is greater than or equal to l, decrement coins by l, increment c by 1, and decrement freq[l] by 1.
    //  6. Return c as the maximum number of ice cream bars that can be bought with the given amount of coins.
    int maxIceCream(vector<int> &costs, int coins)
    {
        int r = *max_element(costs.begin(), costs.end());
        vector<int> freq(r + 1);
        for (int i : costs)
        {
            freq[i]++;
        }
        int c = 0;
        int l = 1;
        while (l <= r && coins > 0)
        {
            while (l <= r && freq[l] == 0)
            {
                l++;
            }
            if (l > r)
                break;
            if ((coins -= l) >= 0)
            {
                c++;
                freq[l]--;
            }
        }
        return c;
    }
};