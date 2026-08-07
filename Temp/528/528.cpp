// Link: https://leetcode.com/problems/random-pick-with-weight/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) pick, O(n) construct  SC: O(n)
// Approach: prefix sums of weights, binary search a uniformly random target
// in [1, total] to find the corresponding index
class Solution {
    vector<int> prefix;

public:
    Solution(vector<int>& w) {
        int sum = 0;
        for (int x : w) { sum += x; prefix.push_back(sum); }
    }

    int pickIndex() {
        int target = rand() % prefix.back() + 1;
        return lower_bound(prefix.begin(), prefix.end(), target) - prefix.begin();
    }
};
