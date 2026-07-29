// Link: https://leetcode.com/problems/sum-of-k-mirror-numbers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(10^7 * log(10^7))  SC: O(1)
//  Approach: Generate palindromic numbers in base 10 and check if they are also palindromic in base k. Keep track of the count and sum of such numbers until we reach n k-mirror numbers.
class Solution
{
public:
    long long kMirror(int k, int n)
    {
        long long c = 0;
        long long sum = 0;
        long long st = 1;
        while (c < n)
        {
            long long end = st * 10;

            for (int i = st; i < end && c < n; i++)
            {
                long long num = gen_palindrome(i, true);
                if (is_basek_palindrome(num, k))
                {
                    sum += num;
                    c++;
                }
            }
            for (int i = st; i < end && c < n; i++)
            {
                long long num = gen_palindrome(i, false);
                if (is_basek_palindrome(num, k))
                {
                    sum += num;
                    c++;
                }
            }
            st = end;
        }
        return sum;
    }

    long long gen_palindrome(long long a, bool is_odd)
    {
        long long ans = a;
        long long p = (is_odd) ? a / 10 : a;
        while (p > 0)
        {
            ans = ans * 10 + (p % 10);
            p /= 10;
        }
        return ans;
    }

    bool is_basek_palindrome(long long a, int k)
    {
        long long og = a;
        long long rev = 0;
        while (a > 0)
        {
            int d = a % k;
            rev = rev * k + d;
            a /= k;
        }
        return og == rev;
    }
};