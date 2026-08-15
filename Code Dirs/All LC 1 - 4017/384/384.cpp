// Link: https://leetcode.com/problems/shuffle-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) reset/shuffle  SC: O(n)
// Approach: keep original array; reset returns a copy; shuffle uses
// Fisher-Yates on a working copy
class Solution {
    vector<int> original;
    vector<int> current;

public:
    Solution(vector<int>& nums) : original(nums), current(nums) {}

    vector<int> reset() {
        current = original;
        return current;
    }

    vector<int> shuffle() {
        for (int i = (int)current.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(current[i], current[j]);
        }
        return current;
    }
};
