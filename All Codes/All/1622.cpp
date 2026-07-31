// Link: https://leetcode.com/problems/fancy-sequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: We can maintain a vector to store the elements of the sequence. We also maintain two variables, mul and add, to keep track of the multiplication and addition operations applied to the sequence. When we append a new value, we adjust it based on the current mul and add values. For getIndex, we compute the final value using the stored value, mul, and add. The modPow function is used to compute the modular inverse for division in modular arithmetic.
class Fancy
{
public:
    vector<long long> arr;
    long long mul;
    long long add;
    long long inverse_mul;
    long long MOD;

    long long modPow(long long a, long long b)
    {
        long long res = 1;
        while (b)
        {
            if (b & 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
    Fancy()
    {
        this->arr = {};
        this->mul = 1;
        this->add = 0;
        this->MOD = 1000000007;
    }

    void append(int val)
    {
        arr.push_back(
            (((val - add + MOD) % MOD) * modPow(mul, (MOD - 2)) % MOD));
    }

    void addAll(int inc) { add = (add + inc) % MOD; }

    void multAll(int m)
    {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx)
    {
        if (idx >= arr.size())
            return -1;
        return (arr[idx] * mul + add) % 1000000007;
    }
};
