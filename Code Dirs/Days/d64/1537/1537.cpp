// Link: https://leetcode.com/problems/get-the-maximum-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m) SC: O(1)
//  Approach: We can use two pointers to iterate through both arrays. We can keep track of the sum of elements in both arrays and whenever we encounter a common element, we can take the maximum of the two sums and add it to the answer. Finally, we can return the answer modulo 1e9 + 7.
class Solution
{
public:
    int maxSum(vector<int> &nums1, vector<int> &nums2)
    {
        int p1 = 0;
        int p2 = 0;
        int n = nums1.size();
        int m = nums2.size();
        long long sum_a = 0;
        long long sum_b = 0;
        long long ans = 0;
        while (p1 < n && p2 < m)
        {
            if (nums1[p1] > nums2[p2])
            {
                sum_b += nums2[p2];
                p2++;
            }
            else if (nums2[p2] > nums1[p1])
            {
                sum_a += nums1[p1];
                p1++;
            }
            else
            {
                ans += (max(sum_a, sum_b) + nums1[p1]);
                p1++;
                p2++;
                sum_a = 0;
                sum_b = 0;
            }
        }
        while (p1 < n)
        {
            sum_a = (sum_a + nums1[p1]);
            p1++;
        }
        while (p2 < m)
        {
            sum_b = (sum_b + nums2[p2]);
            p2++;
        }
        int mod = 1e9 + 7;
        ans = (ans + max(sum_a, sum_b)) % mod;
        return ans;
    }
};