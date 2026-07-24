// Link: https://leetcode.com/problems/closest-divisors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(sqrt(num)), SC: O(1)
    //    Approach:
    //    1. We need to find two integers a and b such that either a * b = num + 1 or a * b = num + 2, and the absolute difference |a - b| is minimized. To achieve this, we can iterate through all possible divisors of num + 1 and num + 2, starting from the square root of the larger of the two numbers and moving downwards. This is because the closest divisors will be around the square root of the number.
    //    2. For each divisor i, we check if (num + 1) % i == 0. If it is, we have found a pair of divisors (i, (num + 1) / i). We can return this pair immediately since we are iterating from the largest possible divisor downwards, ensuring that we find the closest pair first.
    //    3. If (num + 1) % i != 0, we then check if (num + 2) % i == 0. If it is, we have found a pair of divisors (i, (num + 2) / i). Again, we can return this pair immediately.
    //    4. If we finish iterating through all possible divisors without finding any pairs, we return an empty vector. However, this case should not occur for valid inputs since num + 1 and num + 2 will always have divisors.
    vector<int> closestDivisors(int num)
    {
        for (int i = sqrt(num + 2); i > 0; i--)
        {
            if ((num + 1) % i == 0)
            {
                return {i, (num + 1) / i};
            }
            if ((num + 2) % i == 0)
            {
                return {i, (num + 2) / i};
            }
        }
        return {};
    }
};
