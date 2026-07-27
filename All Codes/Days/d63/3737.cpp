// Link: https://leetcode.com/problems/count-subarrays-with-majority-element-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(1)
// Approach: brute force over all subarrays, tracking running count of
// target as the start index is fixed and the end index extends; a
// subarray is counted when 2*count > length (strict majority).
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == target) cnt++;
                int len = j - i + 1;
                if (2 * cnt > len) ans++;
            }
        }
        return ans;
    }
};
