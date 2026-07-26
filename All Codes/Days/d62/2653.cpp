// Link: https://leetcode.com/problems/sliding-subarray-beauty/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 50) — each window update is O(1), each answer lookup scans the
// fixed 50-bucket frequency table
// Approach: sliding window of size k, but instead of sorting each window,
// bucket only the NEGATIVE values (values are bounded in [-50,50]) by
// magnitude in a fixed-size freq table, since beauty is 0 whenever the x-th
// smallest isn't negative. get_xTH_element walks buckets from 50 down to 1,
// subtracting counts until the x-th negative is found, returning it negated.
class Solution {
public:
    int get_xTH_element(int target, vector<int>& freq) {

        for (int i = 50; i >= 1; i--) {

            target -= freq[i];

            if (target <= 0) {
                return -i;
            }
        }

        return 0;
    }

    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {

        int n = nums.size();

        vector<int> freq(51, 0);
        vector<int> ans;

        int neg_count = 0;

        // first window
        for (int i = 0; i < k; i++) {

            if (nums[i] < 0) {
                neg_count++;
                freq[abs(nums[i])]++;
            }
        }

        if (neg_count < x) {
            ans.push_back(0);
        } else {
            ans.push_back(get_xTH_element(x, freq));
        }

        int start = 0;

        for (int end = k; end < n; end++) {

            int a = nums[start];
            int b = nums[end];

            // remove old
            if (a < 0) {
                neg_count--;
                freq[abs(a)]--;
            }

            // add new
            if (b < 0) {
                neg_count++;
                freq[abs(b)]++;
            }

            if (neg_count < x) {
                ans.push_back(0);
            } else {
                ans.push_back(get_xTH_element(x, freq));
            }

            start++;
        }

        return ans;
    }
};
