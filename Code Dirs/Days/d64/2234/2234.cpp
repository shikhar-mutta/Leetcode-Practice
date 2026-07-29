// Link: https://leetcode.com/problems/maximum-total-beauty-of-the-gardens/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + target * log(target) + m * log(m)) where m is the number of incomplete gardens
// SC: O(n + target)
// Approach: We can use a greedy approach to solve this problem. First, we can count the number of gardens that are already full and the number of incomplete gardens. Then, we can sort the incomplete gardens in ascending order and calculate the prefix sum of their flower counts. Next, we can iterate through the number of gardens that we can make full and calculate the maximum beauty we can achieve by either making all gardens full or making all except one full and one garden at target - 1 for partial beauty. Finally, we return the maximum beauty we can achieve.
class Solution
{
public:
    long long maximumBeauty(vector<int> &flowers, long long newFlowers,
                            int target, int full, int partial)
    {
        int n = flowers.size();

        static int cnt[100001];
        static long long pref[100001];

        memset(cnt, 0, target * sizeof(int));

        int alreadyFull = 0;
        int m = 0;
        long long sumIncomplete = 0;

        for (int x : flowers)
        {
            if (x >= target)
            {
                alreadyFull++;
            }
            else
            {
                cnt[x]++;
                m++;
                sumIncomplete += x;
            }
        }

        if (m == 0)
        {
            return 1LL * n * full;
        }

        long long costAllFull = 1LL * m * target - sumIncomplete;

        if (newFlowers >= costAllFull)
        {
            return max(1LL * n * full,
                       1LL * (n - 1) * full + 1LL * (target - 1) * partial);
        }

        int idx = 0;
        pref[0] = 0;

        for (int v = 1; v < target; v++)
        {
            int c = cnt[v];
            while (c-- > 0)
            {
                flowers[idx] = v;
                pref[idx + 1] = pref[idx] + v;
                idx++;
            }
        }

        long long ans = 0;
        long long costFull = 0;

        int p = m - 1;

        for (int madeFull = 0; madeFull <= m; madeFull++)
        {
            long long remain = newFlowers - costFull;
            if (remain < 0)
            {
                break;
            }
            int incompleteLeft = m - madeFull;
            long long current = 1LL * (alreadyFull + madeFull) * full;
            if (incompleteLeft > 0)
            {
                if (p >= incompleteLeft)
                {
                    p = incompleteLeft - 1;
                }
                while (p > 0 &&
                       1LL * flowers[p] * (p + 1) - pref[p + 1] > remain)
                {
                    p--;
                }
                long long used = 1LL * flowers[p] * (p + 1) - pref[p + 1];
                long long minIncomplete =
                    flowers[p] + (remain - used) / (p + 1);
                if (minIncomplete >= target)
                {
                    minIncomplete = target - 1;
                }
                current += minIncomplete * partial;
            }
            if (current > ans)
            {
                ans = current;
            }
            if (madeFull < m)
            {
                costFull += target - flowers[m - 1 - madeFull];
            }
        }

        return ans;
    }
};
