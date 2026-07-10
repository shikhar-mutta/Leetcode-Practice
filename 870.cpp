// Link: https://leetcode.com/problems/advantage-shuffle/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) + O(nlogn) = O(nlogn)
// SC: O(n)
// Approach: Sort nums1 and nums2. Then, for each element in nums2, if the largest remaining element in nums1 is greater than it, assign that element to the answer. Otherwise, assign the smallest remaining element in nums1 to the answer.

class Solution
{
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {

        int n = nums1.size();

        sort(nums1.begin(), nums1.end());

        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            arr.push_back({nums2[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<int> ans(n);
        int left = 0, right = n - 1;

        for (int i = n - 1; i >= 0; i--)
        {
            int val = arr[i].first;
            int idx = arr[i].second;

            if (nums1[right] > val)
            {
                ans[idx] = nums1[right];
                right--;
            }
            else
            {
                ans[idx] = nums1[left];
                left++;
            }
        }

        return ans;
    }
};
