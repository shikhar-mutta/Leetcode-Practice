// Link: https://leetcode.com/problems/count-integers-with-even-digit-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn), SC: O(1)
//    Approach:
//    1. We can iterate through all the numbers from 1 to num and calculate the sum of digits for each number.
//    2. If the sum of digits is even, we can increment the count of even digit sum numbers.
//    3. We can return the count of even digit sum numbers as the answer.
class Solution
{
public:
    int countEven(int num)
    {
        int res = 0;
        for (int i = 1; i <= num; ++i)
        {
            int sum = 0, t = i;
            while (t)
            {
                sum += t % 10;
                t /= 10;
            }
            if (sum % 2 == 0)
                ++res;
        }
        return res;
    }
};