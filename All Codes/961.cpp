// Link: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        unordered_set<int> seen;
        for (int num : nums)
        {
            // If the number is already in the set, it's the repeated element
            if (seen.count(num))
            {
                return num;
            }
            seen.insert(num);
        }
        return -1; // This line should never be reached
    }
};
