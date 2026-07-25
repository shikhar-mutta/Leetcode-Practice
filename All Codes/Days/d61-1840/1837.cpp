// Link: https://leetcode.com/problems/sum-of-digits-in-base-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n), SC: O(1)
//   Approach:
//     1. We can use a while loop to iterate through the digits of the number in base k.
//     2. We can use the modulo operator to get the last digit of the number in base k and add it to the sum.
//     3. We can then divide the number by k to remove the last digit and continue the process until the number becomes 0.
//     4. Finally, we can return the sum of the digits in base k.
class Solution
{
public:
    int sumBase(int n, int k)
    {
        int sum = 0;
        while (n)
        {
            sum += n % k;
            n /= k;
        }
        return sum;
    }
};
