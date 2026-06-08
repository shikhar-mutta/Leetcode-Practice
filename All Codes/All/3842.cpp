// Link: https://leetcode.com/problems/toggle-light-bulbs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    vector<int> toggleLightBulbs(vector<int> &bulbs)
    {
        vector<int> freq(101, 0); // Assuming bulb numbers are between 1 and 100
        for (int bulb : bulbs)
            freq[bulb]++;

        vector<int> result;
        for (int i = 1; i <= 100; i++)
            if (freq[i] % 2 == 1) // If the count is odd, the bulb is toggled on
                result.push_back(i);

        return result;
    }
};
