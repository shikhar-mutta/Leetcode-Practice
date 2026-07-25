// Link: https://leetcode.com/problems/replace-elements-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q), n = nums.size(), q = operations.size()
// SC: O(n)
// Approach: maintain a hash map from value -> current index in nums. For
// each operation [a, b], look up a's index in O(1), overwrite nums at that
// index with b, then update the map (remove a's entry, point b at that
// same index) so future operations referencing b find it correctly.
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> pos;
        for (int i = 0; i < nums.size(); ++i)
            pos[nums[i]] = i;

        for (auto& op : operations) {
            int a = op[0], b = op[1];
            int idx = pos[a];      // guaranteed to exist
            nums[idx] = b;
            pos.erase(a);
            pos[b] = idx;
        }
        return nums;
    }
};
