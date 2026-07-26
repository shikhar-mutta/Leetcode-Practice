// Link: https://leetcode.com/problems/count-beautiful-substrings-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(len + sqrt(k)) – O(sqrt(k)) to factorize k, O(len) for the main pass
// SC: O(len)           – seen map holds at most O(len) distinct (diff, vm) pairs
// Approach: A substring is beautiful if vowels == consonants AND
// vowels*consonants % k == 0. Since vowels==consonants, length=2*vowels and
// vowels^2 % k == 0. Compute n = smallest positive int with n^2 % k == 0
// (via prime factorization: for each prime p^c in k, take p^ceil(c/2)).
// Then for substring [j+1..i] to be beautiful:
//   1) diff[i] == diff[j]  (diff = running vowels - consonants, == 0 means equal)
//   2) vow[i] % n == vow[j] % n  (ensures vowels divisible by n)
// Use prefix map seen[diff][vow%n] → count of prior indices with same state.
class Solution
{
public:
    int beautifulSubstrings(string s, int k)
    {
        int n = 1;
        int len = s.size();
        for (int i = 2, c; i * i <= k; i++)
        {
            for (c = 0; k % i == 0; k /= i, c++)
                ;
            for (int j = 0; j < (c + 1) / 2; j++)
                n *= i;
        }
        if (k > 1)
            n *= k;
        unordered_map<int, unordered_map<int, int>> seen;
        seen[0][0] = 1;
        int vow = 0;
        int diff = 0;
        int count = 0;

        for (int i = 0; i < len; ++i)
        {
            if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or
                s[i] == 'u')
            {
                ++vow;
                ++diff;
            }
            else
                --diff;
            int vm = vow % n;
            count += seen[diff][vm];
            ++seen[diff][vm];
        }
        return count;
    }
};
