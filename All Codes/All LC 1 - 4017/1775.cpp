// Link: https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//  Approach: Greedy
//    1. We can first check if it is possible to make the sums equal by checking if the maximum possible sum of one array is less than the minimum possible sum of the other array
//    2. If it is possible, we can then calculate the difference between the two sums and try to reduce the difference by either increasing the sum of the first array or decreasing the sum of the second array
//    3. We can use a count array to keep track of the number of elements that can be increased or decreased by a certain amount
//    4. We can then iterate through the count array from the largest possible change to the smallest possible change and apply the changes until the difference is reduced to zero or less
//    5. Finally, we can return the number of operations needed to make the sums equal
class Solution
{
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() * 6 < nums2.size() || nums2.size() * 6 < nums1.size())
            return -1;

        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (sum1 > sum2)
            return minOperations(nums2, nums1);

        int ans = 0;
        // increasing in `nums1` and decreasing in `nums2`
        vector<int> count(6);

        for (const int num : nums1)
            ++count[6 - num];

        for (const int num : nums2)
            ++count[num - 1];

        for (int i = 5; sum2 > sum1;)
        {
            while (count[i] == 0)
                --i;
            sum1 += i;
            --count[i];
            ++ans;
        }
        return ans;
    }
};