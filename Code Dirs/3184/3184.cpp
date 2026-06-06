// Link: https://leetcode.com/problems/count-pairs-that-form-a-complete-day-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) SC: O(1)
    int countCompleteDayPairs(vector<int> &hours)
    {
        int count = 0, n = hours.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if ((hours[i] + hours[j]) % 24 == 0)
                    count++;

        return count;
    }
};
