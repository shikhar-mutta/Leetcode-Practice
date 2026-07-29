// Link: https://leetcode.com/problems/find-substring-with-given-hash-value/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
//  Approach: We can use a rolling hash technique to calculate the hash value of each substring of length k in the string s. We can then compare the hash value of each substring with the given hashValue. If they match, we return the substring. We can use modular arithmetic to avoid overflow and to keep the hash values within a manageable range. We can also precompute the powers of p modulo m to avoid recalculating them for each substring. We can iterate through the string from the end to the beginning to ensure that we find the first substring with the given hash value.
class Solution
{
public:
    string subStrHash(string s, int p, int m, int k, int hashValue)
    {
        long long cur = 0, res = 0, pk = 1, n = s.size();
        for (int i = n - 1; i >= 0; --i)
        {
            cur = (cur * p + s[i] - 'a' + 1) % m;
            if (i + k >= n)
                pk = pk * p % m;
            else
                cur = (cur - (s[i + k] - 'a' + 1) * pk % m + m) % m;
            if (cur == hashValue)
                res = i;
        }
        return s.substr(res, k);
    }
};