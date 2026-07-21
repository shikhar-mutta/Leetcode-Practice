// Link: https://leetcode.com/problems/ugly-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(logn)
    // SC: O(1)
    // Approach:
    // 1. Check if the number is less than or equal to 0, if yes return false.
    // 2. Divide the number by 2, 3, and 5 until it is no longer divisible by them.
    // 3. If the number becomes 1, return true, else return false.
    // 4. The number is ugly if it can be expressed as a product of the prime factors 2, 3, and 5 only.
    // 5. If the number has any prime factor other than 2, 3, or 5, it is not ugly.
    // 6. The function returns true if the number is ugly, and false otherwise.
    bool isUgly(int n)
    {
        if (n <= 0)
            return false;
        for (int p : {2, 3, 5})
            while (n % p == 0)
                n /= p;
        return n == 1;
    }
};
