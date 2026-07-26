// Link: https://leetcode.com/problems/replace-elements-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q), n = nums.size(), q = operations.size()
// SC: O(max value) for the global lookup array
// Approach: same idea as a value->index hash map, but implemented as a
// fixed-size global array indexed directly by value (bounded by
// constraints, up to 1e6) for O(1) lookups without hashing overhead. For
// each operation [a, b], find a's index via hsh[a], overwrite nums there
// with b, then repoint hsh[b] to that index and clear hsh[a].
vector<int> hsh(1000010, -1);
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums,
                            vector<vector<int>>& operations) {
        for (int i = 0; i < nums.size(); i++) {
            hsh[nums[i]] = i;
        }
        for (int i = 0; i < operations.size(); i++) {
            nums[hsh[operations[i][0]]] = operations[i][1];
            hsh[operations[i][1]] = hsh[operations[i][0]];
            hsh[operations[i][0]] = -1;
        }
        return nums;
    }
};
