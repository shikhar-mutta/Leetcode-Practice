// Link: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n) where n is the input number
    // SC: O(1)
    //   Approach:
    //    1. Initialize two variables, prod and sum, to store the product and sum of the digits of the input number n.
    //    2. Use a while loop to iterate through each digit of n by taking the modulo 10 of n to get the last digit and then dividing n by 10 to remove the last digit.
    //    3. For each digit, update prod by multiplying it with the digit and update sum by adding the digit to it.
    //    4. After processing all digits, return the difference between prod and sum.
    //    5. The time complexity is O(log n) because the number of digits in n is proportional to log n, and the space complexity is O(1) since we are using a constant amount of extra space.
    //    6. Return the difference between the product and sum of the digits.
    int subtractProductAndSum(int n)
    {
        int prod = 1, sum = 0;
        while (n)
        {
            int d = n % 10;
            prod *= d;
            sum += d;
            n /= 10;
        }
        return prod - sum;
    }
};