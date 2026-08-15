// Link: https://leetcode.com/problems/complete-prime-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(num) * sqrt(num)) SC: O(log num)
// Approach: build every numeric prefix and suffix from the digit string
// and check each is prime via trial division.
class Solution
{
    bool isPrime(long long x)
    {
        if (x < 2)
            return false;
        for (long long p = 2; p * p <= x; p++)
            if (x % p == 0)
                return false;
        return true;
    }

public:
    bool completePrime(int num)
    {
        string s = to_string(num);
        int n = s.size();
        for (int k = 1; k <= n; k++)
        {
            long long pre = stoll(s.substr(0, k));
            long long suf = stoll(s.substr(n - k, k));
            if (!isPrime(pre) || !isPrime(suf))
                return false;
        }
        return true;
    }
};
