// Link: https://leetcode.com/problems/count-numbers-with-unique-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the input number.
    // SC: O(1) as we are using constant space.
    //  Approach:
    //  1. The problem is to count the numbers with unique digits for a given number of digits n.
    //  2. The solution uses a mathematical approach to calculate the count of unique digit numbers.
    //  3. The algorithm iterates through the number of digits and calculates the count of unique digit numbers by multiplying the available digits for each position.
    //  4. The final result is returned as the total count of unique digit numbers for the given number of digits n.
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
            return 1;
        int total = 10;
        int uniqueDigitCount = 9;
        int availableDigits = 9;
        for (int i = 2; i <= n && i <= 10; i++)
        {
            uniqueDigitCount *= availableDigits;
            total += uniqueDigitCount;
            availableDigits--;
        }
        return total;
    }
};
