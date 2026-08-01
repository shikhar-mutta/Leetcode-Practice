// Link: https://leetcode.com/problems/maximum-score-with-co-prime-element/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn)  SC: O(n)
// Approach: We can use the Sieve of Eratosthenes to find the smallest prime factor (spf) for each number up to the maximum value in the nums array. We can then use this information to calculate the frequency of each prime factor in the nums array. For each number in nums, we can find its prime factors using the spf array and use the inclusion-exclusion principle to calculate the number of elements in nums that are not coprime with it. Finally, we can calculate the score for each number and keep track of the maximum score found.
class Solution
{
public:
    int maxScore(vector<int> &nums, int maxVal)
    {
        int mx = maxVal;
        for (int x : nums)
        {
            mx = max(mx, x);
        }
        vector<int> freq(mx + 1, 0);
        for (int x : nums)
        {
            freq[x]++;
        }
        vector<int> spf(mx + 1);
        for (int i = 0; i <= mx; i++)
        {
            spf[i] = i;
        }
        vector<int> mul(mx + 1, 0);
        for (int i = 2; i <= mx; i++)
        {
            if (spf[i] == i)
            {
                for (int j = i * 2; j <= mx; j += i)
                {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
            int m_sum = 0;
            for (int j = i; j <= mx; j += i)
            {
                m_sum += freq[j];
            }
            mul[i] = m_sum;
        }
        int ans = freq[1] > 0 ? 1 : 0;
        for (int i = mx; i >= 2; i--)
        {
            if (i <= ans)
                break;
            if (freq[i] == 0 && i > maxVal)
                continue;
            int x = i;
            int fac[7];
            int cnt = 0;
            while (x != 1)
            {
                int f = spf[x];
                fac[cnt++] = f;
                while (x % f == 0)
                    x /= f;
            }
            int tot = 1 << cnt;
            int m = -freq[i];
            for (int j = 1; j < tot; j++)
            {
                int val = 1;
                for (int k = 0; k < cnt; k++)
                {
                    if ((j >> k) & 1)
                    {
                        val *= fac[k];
                    }
                }
                if (__builtin_popcount(j) & 1)
                    m += mul[val];
                else
                    m -= mul[val];
            }
            int cost = freq[i] > 0 ? (m + freq[i] - 1) : max(m, 1);
            if (i - cost > ans)
            {
                ans = i - cost;
            }
        }
        return ans;
    }
};
