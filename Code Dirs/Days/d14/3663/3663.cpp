// Link: https://leetcode.com/problems/find-the-least-frequent-digit/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n) and SC: O(1)
    int getLeastFrequentDigit(int n)
    {
        vector<int> freq(10, 0);

        while (n > 0) // Store freq of each digit in the number
        {
            int digit = n % 10;
            freq[digit]++;
            n /= 10;
        }

        int minFreq = INT_MAX, ans = -1;

        for (int i = 0; i < 10; i++)
            if (freq[i] > 0)
                minFreq = min(minFreq, freq[i]);

        for (int i = 0; i < 10; i++)
            if (freq[i] == minFreq)
            {
                ans = i;
                break;
            }
        return ans;
    }
};
