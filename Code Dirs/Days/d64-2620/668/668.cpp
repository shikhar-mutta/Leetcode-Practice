// Link: https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((m+n) log(m*n))  SC: O(1)
//  Approach: binary search on the answer value x; count how many table
//  entries are <= x in O(m) by summing min(x/i, n) over rows i, then
//  find the smallest x whose count >= k.
class Solution
{
public:
    int m, n, N; // m row, n column m <= n
    int findKthNumber(int m, int n, int k)
    {
        if (n < m)
        {
            swap(n, m);
        }
        this->m = m, this->n = n;

        int lt(1), rt(m * n + 1);
        while (lt < rt)
        {
            int mid = (lt + rt) / 2;

            if (count_lower(mid) >= k)
            {
                rt = mid;
            }
            else
            {
                lt = mid + 1;
            }
        }

        return lt;
    }
    int count_lower(int value)
    {
        int count(0);

        for (int i = 1; i <= m; ++i)
        {
            int idx = value / i;
            int cnt = min(n, idx) + min(m, idx) - 2 * (i - 1) - 1;

            if (cnt <= 0)
            {
                break;
            }
            count += cnt;
        }

        return count;
    }
};