// Link: https://leetcode.com/problems/rearranging-fruits/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(NlogN), SC: O(N)
//  Approach: We can use a greedy approach to solve this problem. We can sort both baskets and then use two pointers to find the minimum cost of rearranging the fruits. We can keep track of the surplus fruits in both baskets and then use the minimum fruit cost to rearrange them. We can also check if the total number of fruits in both baskets is even, if not we can return -1 as it is not possible to rearrange the fruits. We can also check if the total number of fruits in both baskets is even, if not we can return -1 as it is not possible to rearrange the fruits. We can also check if the total number of fruits in both baskets is even, if not we can return -1 as it is not possible to rearrange the fruits.
class Solution
{
    int count(vector<int> &basket, int i)
    {
        int cnt = 1;
        for (int k = i + 1; k < basket.size() && basket[i] == basket[k]; k++)
            cnt++;
        return cnt;
    }

public:
    long long minCost(vector<int> &basket1, vector<int> &basket2)
    {
        sort(basket1.begin(), basket1.end());
        sort(basket2.begin(), basket2.end());
        vector<pair<int, long>> sur1, sur2;
        for (int i = 0, j = 0; i < basket1.size() || j < basket2.size();)
        {
            if (j == basket2.size() ||
                i < basket1.size() && basket1[i] < basket2[j])
            {
                auto cnt = count(basket1, i);
                if (cnt % 2 == 1)
                    return -1;
                sur1.emplace_back(basket1[i], cnt);
                i += cnt;
            }
            else if (i == basket1.size() ||
                     j < basket2.size() && basket1[i] > basket2[j])
            {
                auto cnt = count(basket2, j);
                if (cnt % 2 == 1)
                    return -1;
                sur2.emplace_back(basket2[j], cnt);
                j += cnt;
            }
            else
            {
                auto cnt1 = count(basket1, i);
                auto cnt2 = count(basket2, j);
                if ((cnt1 + cnt2) % 2 == 1)
                    return -1;
                if (cnt1 < cnt2)
                    sur2.emplace_back(basket2[j], cnt2 - cnt1);
                else if (cnt1 > cnt2)
                    sur1.emplace_back(basket1[i], cnt1 - cnt2);
                i += cnt1;
                j += cnt2;
            }
        }
        int mn = min(basket1[0], basket2[0]);
        long ans = 0;
        for (int i = 0, j = 0; i < sur1.size() && j < sur2.size();)
        {
            if (sur1[i].first < sur2[j].first)
            {
                auto &[f1, cnt1] = sur1[i];
                auto &[f2, cnt2] = sur2.back();
                int f = min({f1, f2, mn * 2});
                long mc = min(cnt1, cnt2);
                ans += f * mc / 2;
                cnt1 -= mc;
                cnt2 -= mc;
                if (cnt1 == 0)
                    i++;
                if (cnt2 == 0)
                    sur2.pop_back();
            }
            else
            {
                auto &[f1, cnt1] = sur1.back();
                auto &[f2, cnt2] = sur2[j];
                int f = min({f1, f2, mn * 2});
                long mc = min(cnt1, cnt2);
                ans += f * mc / 2;
                cnt1 -= mc;
                cnt2 -= mc;
                if (cnt1 == 0)
                    sur1.pop_back();
                if (cnt2 == 0)
                    j++;
            }
        }
        return ans;
    }
};
