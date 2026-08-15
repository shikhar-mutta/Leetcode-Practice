// Link: https://leetcode.com/problems/count-distinct-integers-after-removing-zeros/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) SC: O(log n)
// Approach: removeZeros(x) always yields a zero-digit-free number <= x,
// so the set of distinct results for x in [1,n] is exactly the set of
// zero-digit-free numbers in [1,n] (every such number y<=n is its own
// image via x=y, and every image is one of these numbers). Count them
// with digit DP: sum 9^len over shorter lengths, plus a tight scan over
// n's own digits.
class Solution
{
public:
    long long countDistinct(long long n)
    {
        string s = to_string(n);
        int L = s.size();
        vector<long long> pow9(L + 1);
        pow9[0] = 1;
        for (int i = 1; i <= L; i++)
            pow9[i] = pow9[i - 1] * 9;

        long long total = 0;
        for (int len = 1; len < L; len++)
            total += pow9[len];

        bool possible = true;
        for (int i = 0; i < L; i++)
        {
            int d = s[i] - '0';
            int cnt = max(0, d - 1);
            total += (long long)cnt * pow9[L - i - 1];
            if (d == 0)
            {
                possible = false;
                break;
            }
        }
        if (possible)
            total += 1;
        return total;
    }
};
