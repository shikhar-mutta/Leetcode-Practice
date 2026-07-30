// Link: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n + k log n) where n is the length of the nums array and k is the number of operations
// SC: O(n) where n is the length of the nums array
// Approach: We can use a priority queue to keep track of the indices of the elements in the nums array. We can define a custom comparator that compares the values of the elements at the indices in the priority queue, taking into account the multiplier and the number of times each element has been multiplied. We can then perform k operations by repeatedly popping the top index from the priority queue, multiplying the corresponding element in the nums array by the multiplier, and pushing the index back into the priority queue. We also need to keep track of the number of times each element has been multiplied using an exponent array. After performing k operations, we can compute the final state of the nums array by multiplying each element by the multiplier raised to the power of its corresponding exponent, and taking the result modulo 10^9 + 7.
class Solution
{
public:
    int mult;
    vector<int> *numsPtr;
    vector<long long> *expPtr;

    // true if value(a) < value(b), exact (no overflow)
    bool valueLess(int a, int b)
    {
        auto &nums = *numsPtr;
        auto &exponent = *expPtr;
        long long ea = exponent[a], eb = exponent[b];
        const __int128 CAP = (__int128)4e18;
        if (ea <= eb)
        {
            long long diff = eb - ea;
            __int128 prod = nums[b];
            bool overflowed = false;
            for (long long i = 0; i < diff; i++)
            {
                prod *= mult;
                if (prod > CAP)
                {
                    overflowed = true;
                    break;
                }
            }
            if (overflowed)
                return true;
            return (__int128)nums[a] < prod;
        }
        else
        {
            long long diff = ea - eb;
            __int128 prod = nums[a];
            bool overflowed = false;
            for (long long i = 0; i < diff; i++)
            {
                prod *= mult;
                if (prod > CAP)
                {
                    overflowed = true;
                    break;
                }
            }
            if (overflowed)
                return false;
            return prod < (__int128)nums[b];
        }
    }

    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        int n = nums.size();
        const long long MOD = 1e9 + 7;
        vector<long long> exponent(n, 0);
        mult = multiplier;
        numsPtr = &nums;
        expPtr = &exponent;

        if (multiplier == 1)
        {
            vector<int> ans(n);
            for (int i = 0; i < n; i++)
                ans[i] = nums[i] % MOD;
            return ans;
        }

        auto cmp = [&](int a, int b)
        {
            if (a == b)
                return false;
            bool aLessB = valueLess(a, b);
            bool bLessA = valueLess(b, a);
            if (aLessB)
                return false; // a smaller -> a should be "greater" in max-heap sense to end on top
            if (bLessA)
                return true;
            return a > b; // tie: smaller index preferred (appears first)
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; i++)
            pq.push(i);

        long long bound = min((long long)k, (long long)200 * n + 2000);
        vector<int> picks;
        picks.reserve(bound);
        long long done = 0;
        bool periodic = false;
        const int CONFIRM_WINDOWS = 3; // require this many consecutive matching periods

        while (done < bound)
        {
            int idx = pq.top();
            pq.pop();
            exponent[idx]++;
            pq.push(idx);
            picks.push_back(idx);
            done++;

            if (done % n == 0 && done >= (long long)(CONFIRM_WINDOWS + 1) * n)
            {
                bool same = true;
                int sz = picks.size();
                for (int w = 1; w <= CONFIRM_WINDOWS && same; w++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (picks[sz - n + j] != picks[sz - (w + 1) * n + j])
                        {
                            same = false;
                            break;
                        }
                    }
                }
                if (same)
                {
                    periodic = true;
                    break;
                }
            }
        }

        long long remaining = (long long)k - done;
        if (remaining > 0 && periodic)
        {
            vector<int> pattern(picks.end() - n, picks.end());
            long long fullCycles = remaining / n;
            long long rem = remaining % n;
            for (int i = 0; i < n; i++)
                exponent[i] += fullCycles;
            for (int j = 0; j < rem; j++)
                exponent[pattern[j]]++;
        }
        else if (remaining > 0)
        {
            while (remaining > 0)
            {
                int idx = pq.top();
                pq.pop();
                exponent[idx]++;
                pq.push(idx);
                remaining--;
            }
        }

        auto power = [&](long long b, long long e)
        {
            long long r = 1;
            b %= MOD;
            while (e > 0)
            {
                if (e & 1)
                    r = r * b % MOD;
                b = b * b % MOD;
                e >>= 1;
            }
            return r;
        };

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            long long v = (long long)(nums[i] % MOD) * power(multiplier, exponent[i]) % MOD;
            ans[i] = (int)v;
        }
        return ans;
    }
};
