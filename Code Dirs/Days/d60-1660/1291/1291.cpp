// Link: https://leetcode.com/problems/sequential-digits/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n) where n is the size of the string
// Approach:
//  1. We can generate all the sequential digits numbers by starting from each digit from 1 to 9 and appending the next digit to the current number until we reach 9. We can check if the generated number is within the given range [low, high] and add it to the result vector if it is. Finally, we can sort the result vector and return it.
class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> res;
        for (int start = 1; start <= 9; ++start)
        {
            int num = 0;
            for (int d = start; d <= 9; ++d)
            {
                num = num * 10 + d;
                if (num >= low && num <= high)
                    res.push_back(num);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};