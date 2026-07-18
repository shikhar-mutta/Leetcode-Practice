// Link: https://leetcode.com/problems/closest-subsequence-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^(n/2) * log(2^(n/2))) SC: O(2^(n/2))
// Approach:
//  1. Split the array into two halves.
//  2. Generate all possible sums of subsequences for both halves using recursion.
//  3. Sort the sums of the second half.
//  4. For each sum from the first half, use binary search to find the closest sum from the second half that, when added to the first sum, is closest to the goal.
//  5. Keep track of the minimum absolute difference found during this process and return it as the result.
// 6. This approach leverages the "meet in the middle" technique, which is efficient for problems involving subsets or subsequences, especially when the input size is large.
class Solution
{
public:
    void f(vector<int> &nums, vector<int> &ans, int idx, int sum)
    {
        if (idx < 0)
        {
            ans.push_back(sum);
            return;
        }
        f(nums, ans, idx - 1, sum + nums[idx]);
        f(nums, ans, idx - 1, sum);
    }
    int minAbsDifference(vector<int> &nums, int goal)
    {
        int n = nums.size();
        int a = n / 2, b = n - a;
        vector<int> A(a);
        vector<int> B(b);
        for (int i = 0; i < a; i++)
        {
            A[i] = nums[i];
        }
        for (int i = 0; i < b; i++)
        {
            B[i] = nums[a + i];
        }
        vector<int> temp_a, temp_b;
        f(A, temp_a, A.size() - 1, 0);
        f(B, temp_b, B.size() - 1, 0);

        sort(temp_b.begin(), temp_b.end());
        int ans = INT_MAX;
        for (int i = 0; i < temp_a.size(); i++)
        {
            int lo = 0;
            int hi = temp_b.size() - 1;
            int target = goal - temp_a[i];
            while (lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if (temp_b[mid] == target)
                {
                    return 0;
                }
                else if (temp_b[mid] < target)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            if (hi >= 0)
            {
                int a = abs(temp_a[i] + temp_b[hi] - goal);
                ans = min(a, ans);
            }
            if (lo < temp_b.size())
            {
                int a = abs(temp_a[i] + temp_b[lo] - goal);
                ans = min(a, ans);
            }
        }
        return ans;
    }
};