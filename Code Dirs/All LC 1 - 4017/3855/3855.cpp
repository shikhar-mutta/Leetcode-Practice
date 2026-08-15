// Link: https://leetcode.com/problems/sum-of-k-digit-numbers-in-a-range/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(r-l+1) + log(10^k))  SC: O(1)
// Approach: The sum of all k-digit numbers in the range [l, r] can be calculated using the formula for the sum of an arithmetic series. The k-digit numbers in the range [l, r] can be represented as a sequence of numbers starting from l and ending at r. The sum of this sequence can be calculated using the formula for the sum of an arithmetic series, which is given by (n/2) * (first_term + last_term), where n is the number of terms in the sequence. In this case, n = r - l + 1, first_term = l, and last_term = r. The final answer can be calculated by multiplying this sum by (10^k - 1) / 9, which accounts for the fact that each digit contributes to the total sum based on its position in the number. Since we need to return the answer modulo 10^9 + 7, we also need to calculate the modular inverse of 18 (which is derived from the formula) using Fermat's Little Theorem.
const int MOD = 1e9 + 7;
using ll = long long;

class Solution
{
    ll modPow(ll base, ll exp)
    {
        ll res = 1;
        while (exp)
        {
            if (exp & 1)
            {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            // exp >>= 1;
            exp /= 2;
        }
        return res % MOD;
    }

public:
    int sumOfNumbers(int l, int r, int k)
    {

        // final formula we got is a follows:
        ll inv18 = modPow(18, MOD - 2);

        ll numerator = (((modPow(r - l + 1, k) * (modPow(10, k) - 1)) % MOD) * (r + l)) % MOD;

        ll ans = (numerator * inv18) % MOD;
        return ans;
    }
};