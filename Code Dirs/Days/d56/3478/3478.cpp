// Link: https://leetcode.com/problems/choose-k-elements-with-maximum-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(n) = O(nlogn)
    // SC: O(n)
    // Approach:
    //  1. Create a vector of pairs to store the digit sum, actual value, and original index of each element in the input array.
    //  2. Sort the vector based on the digit sum, actual value, and original index.
    //  3. Iterate through the sorted vector and count the number of swaps needed to place each element in its correct position.
    //  4. Return the count of swaps as the result.
    vector<long long> findMaxSum(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b)
             { return nums1[a] < nums1[b]; });
        vector<long long> ans(n);
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        int i = 0;
        while (i < n)
        {
            int j = i;
            while (j < n && nums1[idx[j]] == nums1[idx[i]])
                j++;
            for (int t = i; t < j; t++)
                ans[idx[t]] = sum;
            for (int t = i; t < j; t++)
            {
                pq.push(nums2[idx[t]]);
                sum += nums2[idx[t]];
                if ((int)pq.size() > k)
                {
                    sum -= pq.top();
                    pq.pop();
                }
            }
            i = j;
        }
        return ans;
    }
};
