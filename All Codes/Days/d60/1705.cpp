// Link: https://leetcode.com/problems/maximum-number-of-eaten-apples/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m) where n is the length of the input arrays and m is the maximum expiry date of apples.
    // SC: O(n + m) for storing the expiry dates of apples.
    // Approach:
    //   1. Create an array to store the number of apples that will expire on each day.
    //   2. Iterate through each day, adding the number of apples that will expire on that day to the array.
    //   3. Keep track of the latest expiry date of apples and the current day.
    //   4. For each day, check if there are any apples that can be eaten (i.e., if the number of apples that will expire on that day is greater than 0).
    //   5. If there are apples that can be eaten, decrement the number of apples that will expire on that day and increment the count of eaten apples.
    //   6. Return the total count of eaten apples after iterating through all the days.
    int eatenApples(vector<int> &apples, vector<int> &days)
    {
        auto n = apples.size();
        vector<int> applesExpiry(n + 20001, 0);
        size_t count = 0;
        size_t lastDay = n;
        size_t latestExpiryPointer = 0;

        for (auto currentDay = 0; currentDay < lastDay; currentDay++)
        {
            if (currentDay < n)
            {
                int currentExpiry = days[currentDay] + currentDay;
                applesExpiry[currentExpiry] += apples[currentDay];
                if (currentExpiry < latestExpiryPointer)
                    latestExpiryPointer = currentExpiry;
                if (currentExpiry > lastDay)
                {
                    lastDay = currentExpiry;
                }
            }
            while ((latestExpiryPointer <= currentDay ||
                    applesExpiry[latestExpiryPointer] == 0) &&
                   latestExpiryPointer < lastDay)
            {
                latestExpiryPointer++;
            }
            if (applesExpiry[latestExpiryPointer] != 0)
            {
                applesExpiry[latestExpiryPointer]--;
                count++;
            }
        }
        return count;
    }
};