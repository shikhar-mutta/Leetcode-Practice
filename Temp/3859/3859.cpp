// Link: https://leetcode.com/problems/count-subarrays-with-k-distinct-integers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: We can use a two-pointer technique to find the number of subarrays with exactly k distinct integers. We maintain a count of the occurrences of each integer in the current window and use two pointers to expand and contract the window as needed. We also keep track of the position of the last occurrence of each integer to ensure that we only count subarrays with exactly k distinct integers. The final result is obtained by summing up the counts of valid subarrays for each position in the array.
int cnts[100001], pos[100000];
template <class F>
void compute(const vector<int> &nums, int k, int m, F fn)
{
    int N = size(nums), cur = 0, i = 0, j = 0;
    while (i < N && !(++cnts[nums[i]] == m && ++cur == k))
        fn(i++, -1);
    if (i < N)
    {
        while (1)
        {
            while (cnts[nums[j]] != m)
                --cnts[nums[j++]];
            fn(i, j);
            if (++i == N)
                break;
            if (++cnts[nums[i]] == m)
                --cnts[nums[j++]];
        }
    }
    while (j < i)
        cnts[nums[j++]] = 0;
}
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k, int m)
    {
        long long res = 0;
        compute(nums, k + 1, 1, [](int i, int j)
                { pos[i] = j; });
        compute(nums, k, m, [&res](int i, int j)
                { if (j > pos[i]) res += j - pos[i]; });
        return res;
    }
};