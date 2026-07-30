// Link: https://leetcode.com/problems/split-the-array-to-make-coprime-products/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*log(max(nums[i]))), SC: O(max(nums[i]))
//  Approach: We can use a sieve to find the smallest prime factor of each number in the array. We can then use a map to keep track of the last index of each prime factor.
//  We can then iterate through the array and for each number, we can find its prime factors and update the last index of each prime factor. We can then check if the current index is equal to the last index of any prime factor. If it is, we can return the current index as the valid split point. If we reach the end of the array without finding a valid split point, we can return -1.
static constexpr int LIM = 1e6 + 1;
static int spf[LIM] = {0};
class sieve
{
public:
    sieve()
    {
        for (int i = 2; i < LIM; ++i)
        {
            if (!spf[i])
            {
                spf[i] = i;
                if (1LL * i * i < LIM)
                {
                    for (int j = i * i; j < LIM; j += i)
                    {
                        if (!spf[j])
                            spf[j] = i;
                    }
                }
            }
        }
    }
} s;
class Solution
{
public:
    int findValidSplit(vector<int> &nums)
    {
        const int n = nums.size();
        int last[LIM] = {0};
        for (int i = 0; i < n; ++i)
        {
            int num = nums[i];
            while (num > 1)
            {
                int p = spf[num];
                last[p] = i;
                while (num % p == 0)
                    num /= p;
            }
        }
        int end = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            int num = nums[i];
            while (num > 1)
            {
                int p = spf[num];
                end = max(end, last[p]);
                while (num % p == 0)
                    num /= p;
            }
            if (i == end)
                return i;
        }
        return -1;
    }
};
