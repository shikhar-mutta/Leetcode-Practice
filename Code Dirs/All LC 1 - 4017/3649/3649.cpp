// Link: https://leetcode.com/problems/number-of-perfect-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn)
    // SC: O(n)
    // Approach:
    //  1. We can find the number of perfect pairs by first taking the absolute value of each element in the array and sorting the array.
    //  2. We can then use a two-pointer approach to count the number of perfect pairs. We can initialize two pointers, one at the beginning of the array and one at the end of the array. We can then iterate through the array and for each element, we can check if the absolute value of the element at the left pointer is less than or equal to half of the absolute value of the element at the right pointer. If it is, we can increment the left pointer and add the number of elements between the two pointers to the count of perfect pairs. If it is not, we can decrement the right pointer. We can continue this process until the left pointer is greater than or equal to the right pointer.
    //  3. Finally, we can return the count of perfect pairs.
    long long perfectPairs(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
            v[i] = llabs((long long)nums[i]);
        sort(v.begin(), v.end());

        long long ans = 0;
        int lo = 0;
        for (int j = 0; j < n; j++)
        {
            while (2 * v[lo] < v[j])
                lo++;
            ans += j - lo;
        }
        return ans;
    }
};
