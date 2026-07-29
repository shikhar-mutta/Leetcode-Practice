// Link: https://leetcode.com/problems/count-vowels-permutation/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(1)
// Approach: DP over counts per vowel ending the string so far, using
// the fixed transition rules (a->e; e->a,i; i->a,e,o,u; o->i,u; u->a),
// applying them for n-1 steps, all mod 1e9+7.
class Solution
{
public:
    int countVowelPermutation(int n)
    {
        const long long MOD = 1e9 + 7;
        long long a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int step = 1; step < n; step++)
        {
            long long na = (e + i + u) % MOD;
            long long ne = (a + i) % MOD;
            long long ni = (e + o) % MOD;
            long long no = i;
            long long nu = (i + o) % MOD;
            a = na;
            e = ne;
            i = ni;
            o = no;
            u = nu;
        }
        return (int)((a + e + i + o + u) % MOD);
    }
};
