// Link: https://leetcode.com/problems/super-pow/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(b)) where b is the exponent represented by the vector. The recursive calls reduce the size of the exponent by a factor of 10 each time, leading to a logarithmic number of calls.
// SC: O(log(b)) for the recursion stack. Each recursive call adds a new layer to the stack, and since the size of the exponent is reduced by a factor of 10 with each call, the maximum depth of the recursion is logarithmic in the size of the exponent.
// Approach:
//   1. Use modular exponentiation to compute a^b % mod efficiently.
//   2. Since b is represented as a vector of digits, we can break down the exponentiation into smaller parts using the property that a^(10x + y) = (a^10)^x * a^y.
//   3. Recursively compute the result for the smaller exponent (b without the last digit) and combine it with the result of a raised to the last digit of b, applying the modulo at each step to prevent overflow and ensure correctness.
//   4. The base case for the recursion is when the vector b is empty, in which case we return 1 (since any number to the power of 0 is 1).
//   5. The final result is computed by multiplying the results of the two parts and taking modulo 1337 to get the final answer.
const long long mod = 1337;
class Solution
{
public:
    int superPow(int a, vector<int> &b)
    {
        if (b.empty())
            return 1;
        int res = b.back();
        b.pop_back();
        return binpow(superPow(a, b), 10) * binpow(a, res) % mod;
    }

    long long binpow(long long a, long long b)
    {
        int res = 1;
        a %= mod;
        while (b)
        {
            if (b & 1)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }

        return res;
    }
};