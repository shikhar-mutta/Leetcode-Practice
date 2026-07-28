// Link: https://leetcode.com/problems/number-of-squareful-arrays/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n!) pruned heavily by adjacency check  SC: O(n)
// Approach: sort nums, then backtrack building a permutation. At each
// step, skip duplicate values already tried at this position (standard
// permutation-dedup rule: only use an unused duplicate if the previous
// copy was already used), and only extend if the new element forms a
// perfect square sum with the last placed element.
class Solution {
    int ans = 0;
    bool isSquare(int a, int b) {
        int s = a + b;
        int r = (int)round(sqrt((double)s));
        return r * r == s;
    }
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& cur) {
        if ((int)cur.size() == (int)nums.size()) { ans++; return; }
        for (int i = 0; i < (int)nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            if (!cur.empty() && !isSquare(cur.back(), nums[i])) continue;
            used[i] = true;
            cur.push_back(nums[i]);
            backtrack(nums, used, cur);
            cur.pop_back();
            used[i] = false;
        }
    }
public:
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<int> cur;
        backtrack(nums, used, cur);
        return ans;
    }
};
