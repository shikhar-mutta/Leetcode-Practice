// Link: https://leetcode.com/problems/count-subarrays-with-majority-element-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
//  Approach: use a prefix sum and a hash map to track the difference between the count of target and non-target elements.
class Solution
{
public:
    int countMajoritySubarrays(vector<int> &nums, int target)
    {
        int n = nums.size(), pref = 0, diff = 0, ans = 0, pointer = n;
        vector<int> freq(n * 2 + 1);
        freq[pointer] = 1;
        for (int i = 0; i < n; i++)
        {
            pref += (nums[i] == target ? freq[pointer++] : -freq[--pointer]);
            ans += pref;
            freq[pointer]++;
        }

        return ans;
    }
};