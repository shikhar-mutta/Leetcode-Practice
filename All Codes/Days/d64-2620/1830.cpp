// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
//  Approach: We can use combinatorics to calculate the number of permutations that are lexicographically smaller than the given string. We can calculate the factorial of the length of the string and divide it by the factorial of the frequency of each character to account for duplicates. We can then iterate through the string and for each character, count how many characters are smaller than it and calculate the number of permutations that can be formed with the remaining characters. We can use modular arithmetic to handle large numbers and return the final answer modulo 10^9 + 7.
class Solution
{
public:
    long long MOD = 1e9 + 7;

    long long power(long long base, long long exp)
    {
        long long res = 1;
        base %= MOD;
        while (exp > 0)
        {
            if (exp % 2 == 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) { return power(n, MOD - 2); }
    int makeStringSorted(string s)
    {
        int n = s.size();
        vector<long long> fact(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }
        long long denom = 1;
        for (int i = 0; i < 26; i++)
        {
            denom = (denom * fact[freq[i]]) % MOD;
        }
        long long in_den = modInverse(denom);
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < s[i] - 'a'; j++)
                sum += freq[j];
            long long current =
                (((sum * fact[n - 1 - i]) % MOD) * in_den) % MOD;
            ans = (ans + current) % MOD;
            int char_idx = s[i] - 'a';
            in_den = (freq[char_idx] * in_den) % MOD;
            freq[char_idx] -= 1;
        }
        return ans;
    }
};
