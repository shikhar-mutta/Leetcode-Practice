// Link: https://leetcode.com/problems/first-unique-even-element/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int firstUniqueEven(vector<int> &nums)
    {
        vector<int> freq(101, 0);
        for (int num : nums)
            freq[num]++;
        for (int num : nums)
            if (num % 2 == 0 && freq[num] == 1)
                return num;
        return -1;
    }
};
