// Link: https://leetcode.com/problems/check-digitorial-permutation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) SC: O(1)
//  Approach: a "digitorial" number equals the sum of the factorials of
//  its own digits (e.g. 145 = 1! + 4! + 5!). Compute that sum and compare.
class Solution
{
public:
    bool isDigitorialPermutation(int n)
    {
        static int fact[10] = {0};
        static bool init = false;

        if (!init)
        {
            fact[0] = 1;
            for (int i = 1; i < 10; i++)
                fact[i] = fact[i - 1] * i;
            init = true;
        }

        int pelorunaxi = n;

        int sum = 0;
        int x = n;
        while (x > 0)
        {
            sum += fact[x % 10];
            x /= 10;
        }

        string a = to_string(sum);
        string b = to_string(pelorunaxi);

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        return a == b;
    }
};