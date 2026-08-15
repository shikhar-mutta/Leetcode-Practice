// Link: https://leetcode.com/problems/boats-to-save-people/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + limit) = O(n)
// SC: O(limit) = O(n)
// Approach: Count the frequency of each weight. Then, use two pointers to find the heaviest and lightest person. If they can fit in a boat together, decrement their frequencies. Otherwise, decrement the frequency of the heaviest person. Increment the boat count for each iteration.
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        vector<int> freq(limit + 1, 0);
        for (int w : people)
            freq[w]++;

        int l = 1;
        int r = limit;
        int boats = 0;
        while (l <= r)
        {
            while (l <= r && freq[l] == 0)
                l++;
            while (l <= r && freq[r] == 0)
                r--;
            if (l > r)
                break;
            freq[r]--;
            boats++;
            if (l + r <= limit && freq[l] > 0)
                freq[l]--;
        }
        return boats;
    }
};