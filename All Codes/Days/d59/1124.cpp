// Link: https://leetcode.com/problems/longest-well-performing-interval/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input array hours
    // SC: O(n) where n is the length of the input array hours
    //  Approach:
    //   1. We can use a prefix sum approach to keep track of the number of tiring and non-tiring days.
    //   2. We can use a hash map to store the first occurrence of each prefix sum value.
    //   3. We can iterate through the input array and update the prefix sum value based on whether the current day is tiring or non-tiring.
    //   4. If the prefix sum value is greater than 0, we can update the answer with the current index + 1.
    //   5. If the prefix sum value is less than or equal to 0, we can check if the prefix sum value - 1 exists in the hash map. If it does, we can update the answer with the current index - the index of the first occurrence of the prefix sum value - 1.
    //   6. Finally, we return the answer which contains the length of the longest well-performing interval.
    int longestWPI(vector<int> &hours)
    {
        int ans = 0;
        int value = 0;
        int prefix = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < hours.size(); i++)
        {
            if (hours[i] > 8)
            {
                value = 1;
            }
            else
            {
                value = -1;
            }
            prefix += value;
            if (prefix > 0)
            {
                ans = i + 1;
            }
            else
            {
                if (mp.count(prefix - 1))
                {
                    ans = max(ans, i - mp[prefix - 1]);
                }
            }
            if (!mp.count(prefix))
                mp[prefix] = i;
        }
        return ans;
    }
};