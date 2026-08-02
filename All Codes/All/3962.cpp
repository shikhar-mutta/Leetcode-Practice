// Link: https://leetcode.com/problems/maximum-subarray-sum-after-at-most-k-swaps/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 log k)  SC: O(n)
// Approach: We can use a priority queue to maintain the k smallest elements of the current subarray. We can also maintain the sum of the L-k largest elements in the current subarray. We can also maintain the sum of the k largest elements in the entire array A \ S_in_top. We can also maintain the index of the k-th largest available element in A. We can iterate through all possible subarrays and update the sums accordingly. We can also use a map to mark the indices of elements in the current S_in_top set. We can also use a precomputed array to store the sum of the L largest elements of the entire array nums.
class Solution
{
public:
    long long maxSum(vector<int> &nums, int k)
    {
        int n = nums.size();

        // A stores values and their original indices to distinguish duplicate
        // values
        vector<pair<int, int>> A(n);
        for (int i = 0; i < n; i++)
            A[i] = {nums[i], i};
        sort(A.begin(), A.end(), greater<pair<int, int>>());

        // Precompute the sum of the L largest elements of the entire array nums
        vector<long long> pre_A(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre_A[i + 1] = pre_A[i] + A[i].first;

        long long ans = -2e18;

        // If at most k swaps allow picking any L elements from the entire array
        // (i.e., min(L, n-L) <= k), then the maximum sum for length L is
        // pre_A[L].
        for (int L = 1; L <= n; L++)
        {
            if (L <= k || n - L <= k)
            {
                ans = max(ans, pre_A[L]);
            }
        }

        // If k is large enough, min(L, n-L) is always <= k
        if (k >= n / 2)
            return ans;

        // Map original index of an element in nums to its rank in the sorted
        // array A
        vector<int> pos_in_A(n);
        for (int i = 0; i < n; i++)
            pos_in_A[A[i].second] = i;

        // is_in_top_mark marks indices of elements in the current S_in_top set
        vector<int> is_in_top_mark(n, 0);

        // For each possible subarray starting at i
        for (int i = 0; i < n; i++)
        {
            int current_mark = i + 1;
            // k_small maintains the k smallest elements of the current subarray
            priority_queue<pair<int, int>> k_small;
            // sum_in_top is the sum of the L-k largest elements in the subarray
            long long sum_in_top = 0;
            // sum_k_large_A is the sum of the k largest elements in A
            // \ S_in_top
            long long sum_k_large_A = pre_A[k];
            // last_idx is the index of the k-th largest available element in A
            int last_idx = k - 1;

            for (int j = i; j < n; j++)
            {
                int val = nums[j];
                int L = j - i + 1;

                if (k > 0 && (int)k_small.size() < k)
                {
                    k_small.push({val, j});
                }
                else
                {
                    int v_idx;
                    int v_val;

                    // Identify the element that will move into the S_in_top set
                    if (k > 0 && val < k_small.top().first)
                    {
                        v_val = k_small.top().first;
                        v_idx = k_small.top().second;
                        k_small.pop();
                        k_small.push({val, j});
                    }
                    else
                    {
                        v_val = val;
                        v_idx = j;
                    }

                    // Element v moves to S_in_top. Update sum_in_top and
                    // available elements in A.
                    sum_in_top += v_val;
                    int idx = pos_in_A[v_idx];
                    is_in_top_mark[idx] = current_mark;

                    // Update the sum of the k largest available elements in A
                    if (idx <= last_idx)
                    {
                        sum_k_large_A -= A[idx].first;
                        last_idx++;
                        while (last_idx < n &&
                               is_in_top_mark[last_idx] == current_mark)
                            last_idx++;
                        if (last_idx < n)
                            sum_k_large_A += A[last_idx].first;
                    }

                    // Only need to process subarrays where min(L, n-L) > k
                    if (L > k && L < n - k)
                    {
                        ans = max(ans, sum_in_top + sum_k_large_A);
                    }
                }
            }
        }

        return ans;
    }
};
