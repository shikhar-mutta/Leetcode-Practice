// Link: https://leetcode.com/problems/maximum-and-minimum-sums-of-at-most-size-k-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach: Use a monotonic stack to find the next greater and next smaller elements for each index. For each element, calculate the number of subarrays where it is the maximum or minimum using the distances to the next greater and next smaller elements. Use a helper function to count the number of valid pairs of left and right boundaries for subarrays of size at most k. Sum the contributions of each element to the total maximum and minimum sums and return the result.
class Solution
{
public:
    long long countPairs(long long left, long long right, long long k)
    {
        long long A = min(left, k); // a không thể lớn hơn k

        // Với a nhỏ, k + 1 - a >= right
        // => chọn được full right choices
        long long full = min(A, max(0LL, k + 1 - right));

        long long ans = full * right;

        // Phần còn lại là decreasing:
        // k + 1 - (full + 1), ..., k + 1 - A
        long long cnt = A - full;

        if (cnt > 0)
        {
            long long first = k + 1 - (full + 1);
            long long last = k + 1 - A;

            ans += (first + last) * cnt / 2;
        }

        return ans;
    }

    long long calc(vector<int> &nums, int k, bool isMax)
    {
        int n = nums.size();
        vector<int> st;
        long long res = 0;

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() &&
                   (i == n || (isMax ? nums[st.back()] <= nums[i]
                                     : nums[st.back()] >= nums[i])))
            {

                int mid = st.back();
                st.pop_back();

                int leftBoundary = st.empty() ? -1 : st.back();
                int rightBoundary = i;

                long long left = mid - leftBoundary;
                long long right = rightBoundary - mid;

                long long cnt = countPairs(left, right, k);

                res += 1LL * nums[mid] * cnt;
            }

            st.push_back(i);
        }

        return res;
    }

    long long minMaxSubarraySum(vector<int> &nums, int k)
    {
        return calc(nums, k, true) + calc(nums, k, false);
    }
};
