// Link: https://leetcode.com/problems/prime-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sqrt(n) * log(n)) where n is the number of digits in the number. The outer loop generates palindromic numbers, and the inner loop checks for primality, which takes O(sqrt(n)) time. The number of palindromic numbers generated is proportional to the number of digits in the number, which is log(n).
// SC: O(1) as we are using a constant amount of space.
// Approach:
//  1. We first check for small prime palindromes (2, 3, 5, 7, 11) and return them if n is less than or equal to any of these values.
//  2. For larger values of n, we generate palindromic numbers by taking the first half of the number and appending its reverse to it. This is done in the makePalindrome function.
//  3. We then check if the generated palindromic number is prime using the isPrime function. If it is prime and greater than or equal to n, we return it.
//  4. If no prime palindrome is found, we return -1 (though this case will not occur for valid inputs as there are infinitely many prime palindromes).
//  5. The isPrime function checks for primality by testing divisibility from 2 up to the square root of the number.

class Solution
{
public:
    int makePalindrome(int x)
    {
        int ans = x;
        x /= 10;
        while (x)
        {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
    bool isPrime(int n)
    {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int primePalindrome(int n)
    {
        if (n <= 2)
            return 2;
        if (n <= 3)
            return 3;
        if (n <= 5)
            return 5;
        if (n <= 7)
            return 7;
        if (n <= 11)
            return 11;

        for (int i = 10;; i++)
        {
            int ans = makePalindrome(i);
            if (ans >= n && isPrime(ans))
                return ans;
        }

        return -1;
    }
};