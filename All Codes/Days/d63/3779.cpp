// Link: https://leetcode.com/problems/minimum-number-of-operations-to-have-distinct-elements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: each operation strips the first 3 (or fewer) elements. The
// remaining suffix starting at index s is duplicate-free iff s exceeds
// every index that is not its value's last occurrence (any earlier
// occurrence inside the suffix would collide with the later one). So
// find m = max index whose value reoccurs later, set required suffix
// start s = m+1, and the answer is ceil(s/3) operations.
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> lastOcc;
        for (int i = 0; i < n; i++) lastOcc[nums[i]] = i;

        int m = -1;
        for (int i = 0; i < n; i++) if (lastOcc[nums[i]] != i) m = max(m, i);

        int s = m + 1;
        return (s + 2) / 3;
    }
};
