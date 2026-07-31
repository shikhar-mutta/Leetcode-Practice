// Link: https://leetcode.com/problems/count-anagrams/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(1)
// Approach: The problem is to count the number of anagrams that can be formed from the words in a given string. The solution involves splitting the string into words, counting the frequency of each character in each word, and calculating the number of anagrams using the formula for permutations of multisets. The result is computed modulo 10^9 + 7. The solution uses a helper function to calculate the modular exponentiation for computing the modular inverse of the factorial of character counts.
class Solution
{
public:
    const int mod = 1e9 + 7;

    int countAnagrams(string s)
    {
        stringstream ss(s);
        string w;
        long ans = 1, mul = 1;
        while (ss >> w)
        {
            int cnt[26] = {0};
            for (int i = 1; i <= w.size(); ++i)
            {
                int c = w[i - 1] - 'a';
                ++cnt[c];
                ans = ans * i % mod;
                mul = mul * cnt[c] % mod;
            }
        }
        return ans * pow(mul, mod - 2) % mod;
    }

    long pow(long x, int n)
    {
        long res = 1L;
        for (; n; n /= 2)
        {
            if (n % 2)
                res = res * x % mod;
            x = x * x % mod;
        }
        return res;
    }
};
