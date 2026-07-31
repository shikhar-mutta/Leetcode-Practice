// Link: https://leetcode.com/problems/find-the-closest-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(len)  SC: O(len)
// Approach: any nearest palindrome (other than n itself) comes from one
// of a small candidate set: mirror the left half of n as-is, mirror the
// left half incremented by 1, mirror the left half decremented by 1, or
// the boundary values 10^(len-1)-1 (all 9's, one digit shorter) and
// 10^(len-1)+1 (power of 10 plus 1, one digit longer). Pick the closest
// candidate != n, breaking ties toward the smaller value.
class Solution
{
public:
    long long makepalin(long long x, bool par)
    {
        long long ans = x;
        if (par)
            x /= 10;

        while (x > 0)
        {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }

    string nearestPalindromic(string n)
    {
        int len = n.size();
        if (len == 1)
            return to_string(stoi(n) - 1);

        long long num = stoll(n);
        int preflen = (len + 1) / 2;

        long long pref = stoll(n.substr(0, preflen));

        vector<long long> cand;

        cand.push_back(makepalin(pref, len % 2));
        cand.push_back(makepalin(pref - 1, len % 2));
        cand.push_back(makepalin(pref + 1, len % 2));

        long long big = 1;
        for (int i = 0; i < len; i++)
            big *= 10;
        cand.push_back(big + 1);
        cand.push_back((big / 10) - 1);

        long long best = -1;
        for (long long i : cand)
        {
            if (i == num)
                continue;
            if (best == -1)
            {
                best = i;
                continue;
            }
            long long d1 = abs(num - i);
            long long d2 = abs(num - best);
            if (d1 < d2 || (d1 == d2 && i < best))
                best = i;
        }
        return to_string(best);
    }
};
