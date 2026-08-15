// Link: https://leetcode.com/problems/maximum-total-value/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log(maxVal))  SC: O(1)
// Approach:
//  We can use binary search to find the maximum total value. We can use a greedy approach to find the maximum total value. We can iterate through all the items and check if we can take the item or not. If we can take the item, we will take it and add its value to the total value. If we cannot take the item, we will skip it and move to the next item. We will keep track of the number of items we have taken and if we have taken m items, we will return the total value.
class Solution
{
public:
    int maxTotalValue(vector<int> &value, vector<int> &decay, int m)
    {
        constexpr long long mod = 1000000007LL;
        int n = (int)value.size();
        if (m <= 4)
        {
            long long best[4] = {};
            for (int i = 0; i < n; ++i)
            {
                long long cur = value[i];
                int d = decay[i];
                for (int j = 0; j < m && cur > 0; ++j, cur -= d)
                {
                    if (cur <= best[m - 1])
                        continue;
                    int pos = m - 1;
                    while (pos > 0 && best[pos - 1] < cur)
                    {
                        best[pos] = best[pos - 1];
                        --pos;
                    }
                    best[pos] = cur;
                }
            }
            long long ans = 0;
            for (int i = 0; i < m; ++i)
                ans += best[i];
            return (int)(ans % mod);
        }
        if (n == 1)
        {
            long long cnt =
                min((long long)m, ((long long)value[0] - 1) / decay[0] + 1);
            long long last = (long long)value[0] - (cnt - 1) * decay[0];
            long long ans = cnt * ((long long)value[0] + last) / 2;
            return (int)(ans % mod);
        }
        const int *__restrict val = value.data();
        const int *__restrict dec = decay.data();
        int maxVal = 0;
        int maxCnt = 0;
        int low = 0;
        int firstVal = val[0];
        int firstDec = dec[0];
        bool sameVal = true;
        bool sameDec = true;
        bool singleOnly = true;
        long long firstSum = 0;
        long long step = (long long)m - 1;
        for (int i = 0; i < n; ++i)
        {
            int curVal = val[i];
            int curDec = dec[i];
            if (curVal > maxVal)
            {
                maxVal = curVal;
                maxCnt = 1;
            }
            else if (curVal == maxVal)
                ++maxCnt;
            sameVal &= curVal == firstVal;
            sameDec &= curDec == firstDec;
            singleOnly &= curDec >= curVal;
            firstSum += curVal;
            long long solo = (long long)curVal - step * curDec;
            if (solo > low)
                low = (int)solo;
        }
        if (maxCnt >= m)
            return (int)(1LL * m * maxVal % mod);
        if (maxVal == 1)
            return min(m, n);
        if (sameVal && sameDec)
        {
            long long perCnt = ((long long)firstVal - 1) / firstDec + 1;
            long long totalCnt = min((long long)m, perCnt * n);
            long long fullCnt = totalCnt / n;
            long long remCnt = totalCnt - fullCnt * n;
            long long ans = 0;
            if (fullCnt)
            {
                long long last = (long long)firstVal - (fullCnt - 1) * firstDec;
                ans +=
                    (long long)n * fullCnt * ((long long)firstVal + last) / 2;
            }
            if (remCnt)
                ans += remCnt * ((long long)firstVal - fullCnt * firstDec);
            return (int)(ans % mod);
        }
        if (singleOnly)
        {
            if (m >= n)
                return (int)(firstSum % mod);
            int lo = 1;
            int hi = maxVal + 1;
            while (lo + 1 < hi)
            {
                int mid = lo + ((hi - lo) >> 1);
                int cnt = 0;
                for (int i = 0; i < n; ++i)
                {
                    cnt += val[i] >= mid;
                    if (cnt >= m)
                        break;
                }
                if (cnt >= m)
                    lo = mid;
                else
                    hi = mid;
            }
            int edge = lo;
            int cntGt = 0;
            long long ans = 0;
            for (int i = 0; i < n; ++i)
            {
                int curVal = val[i];
                if (curVal > edge)
                {
                    ++cntGt;
                    ans += curVal;
                }
            }
            ans += 1LL * (m - cntGt) * edge;
            return (int)(ans % mod);
        }
        if (m > n && low == 0)
        {
            int posCnt = 0;
            for (int i = 0; i < n; ++i)
            {
                posCnt += (val[i] - 1) / dec[i] + 1;
                if (posCnt >= m)
                    break;
            }
            if (posCnt < m)
            {
                long long ans = 0;
                for (int i = 0; i < n; ++i)
                {
                    int cnt = (val[i] - 1) / dec[i] + 1;
                    int last = val[i] - (cnt - 1) * dec[i];
                    ans += 1LL * cnt * (val[i] + last) / 2;
                }
                return (int)(ans % mod);
            }
        }
        if (sameDec && firstDec == 1)
        {
            int high = maxVal + 1;
            while (low + 1 < high)
            {
                int mid = low + ((high - low) >> 1);
                int cnt = 0;
                for (int i = 0; i < n; ++i)
                {
                    int curVal = val[i];
                    if (curVal >= mid)
                    {
                        cnt += curVal - mid + 1;
                        if (cnt >= m)
                            break;
                    }
                }
                if (cnt >= m)
                    low = mid;
                else
                    high = mid;
            }
            int edge = low;
            int cntGt = 0;
            long long ans = 0;
            for (int i = 0; i < n; ++i)
            {
                int curVal = val[i];
                if (curVal > edge)
                {
                    int cnt = curVal - edge;
                    cntGt += cnt;
                    ans += 1LL * cnt * (curVal + edge + 1) / 2;
                }
            }
            ans += 1LL * (m - cntGt) * edge;
            return (int)(ans % mod);
        }
        int high = maxVal + 1;
        while (low + 1 < high)
        {
            int mid = low + ((high - low) >> 1);
            int cnt = 0;
            for (int i = 0; i < n; ++i)
            {
                int curVal = val[i];
                if (curVal >= mid)
                {
                    cnt += (curVal - mid) / dec[i] + 1;
                    if (cnt >= m)
                        break;
                }
            }
            if (cnt >= m)
                low = mid;
            else
                high = mid;
        }
        int edge = low;
        int cntGt = 0;
        long long ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int curVal = val[i];
            if (curVal > edge)
            {
                int cnt = (curVal - edge - 1) / dec[i] + 1;
                int last = curVal - (cnt - 1) * dec[i];
                cntGt += cnt;
                ans += 1LL * cnt * (curVal + last) / 2;
            }
        }
        ans += 1LL * (m - cntGt) * edge;
        return (int)(ans % mod);
    }
};
