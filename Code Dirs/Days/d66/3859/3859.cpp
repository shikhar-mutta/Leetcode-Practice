// Link: https://leetcode.com/problems/count-subarrays-with-k-distinct-integers/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: want subarrays with exactly k distinct values, each appearing
// >= m times. Use the "exactly k" = atMost(k) - atMost(k+1) trick, but with
// "atMost" redefined via f(lim): a sliding window shrunk from the left
// whenever it has >= lim distinct values AND >= k of them already meet the
// >= m frequency threshold; after each right-extension, add the current
// left boundary count (valid starting points for a "not yet violating"
// window) to the total. f(k) - f(k+1) isolates windows with exactly k
// qualifying distinct values.
class Solution {
    long long f(vector<int>& nums, int k, int m, int lim) {
        unordered_map<int,int> cnt;
        long long ans = 0;
        int l = 0, t = 0;
        for (int x : nums) {
            if (++cnt[x] == m) t++;
            while ((int)cnt.size() >= lim && t >= k) {
                int y = nums[l++];
                if (--cnt[y] == m - 1) t--;
                if (cnt[y] == 0) cnt.erase(y);
            }
            ans += l;
        }
        return ans;
    }
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        return f(nums, k, m, k) - f(nums, k, m, k + 1);
    }
};
