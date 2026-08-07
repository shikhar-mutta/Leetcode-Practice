// Link: https://leetcode.com/problems/contains-duplicate-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log k)  SC: O(k)
// Approach: sliding window of size indexDiff maintained as a sorted set (ordered by value); for each
// new number, check candidates in [num-valueDiff, num+valueDiff] via lower_bound
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window;
        for (int i = 0; i < (int)nums.size(); i++) {
            long long num = nums[i];
            auto it = window.lower_bound(num - valueDiff);
            if (it != window.end() && *it <= num + (long long)valueDiff) return true;
            window.insert(num);
            if ((int)window.size() > indexDiff) window.erase(nums[i - indexDiff]);
        }
        return false;
    }
};
