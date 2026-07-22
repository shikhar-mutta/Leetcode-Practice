// Link: https://leetcode.com/problems/perfect-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(sqrt(n)) where n is the input number
    // SC: O(1)
    // Approach:
    //  1. If the number is less than or equal to 1, return false
    //  2. Initialize a variable sum to 1 (since 1 is a divisor of every number)
    //  3. Iterate from 2 to the square root of the number
    //  4. If the number is divisible by the current iterator, add both the iterator and the quotient to the sum
    //  5. Finally, check if the sum is equal to the original number and return the result.
    bool checkPerfectNumber(int num)
    {
        if (num <= 1)
            return false;
        int sum = 1;
        for (int i = 2; (long long)i * i <= num; i++)
        {
            if (num % i == 0)
            {
                sum += i;
                if (i != num / i)
                    sum += num / i;
            }
        }
        return sum == num;
    }
};
