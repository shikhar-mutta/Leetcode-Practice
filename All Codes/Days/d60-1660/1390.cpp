// Link: https://leetcode.com/problems/four-divisors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n*sqrt(m)), SC: O(1)
    // Approach:
    //  1. For each number in the input array, we will find its divisors by iterating from 1 to the square root of the number.
    //  2. For each divisor found, we will check if it is a perfect square to avoid counting the same divisor twice.
    //  3. We will keep track of the number of divisors found and their sum. If the number of divisors exceeds 4, we will break out of the loop early.
    //  4. If the number of divisors is exactly 4, we will add the sum of the divisors to the total sum.
    //  5. Finally, we will return the total sum of all divisors for numbers that have exactly 4 divisors.
    int sumFourDivisors(vector<int> &nums)
    {
        int totalSum = 0;
        for (int num : nums)
        {
            int divisors = 0;
            int current = 0;
            for (int i = 1; i * i <= num; i++)
            {
                if (num % i == 0)
                {
                    divisors++;
                    current += i;

                    if (i * i != num)
                    {
                        divisors++;
                        current += num / i;
                    }
                }
                if (divisors > 4)
                    break;
            }
            if (divisors == 4)
                totalSum += current;
        }
        return totalSum;
    }
};