// Link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
// Approach: coordinate-compress values, BIT over rank, scan right to left
// querying count of smaller ranks seen so far, then insert current rank
class Solution {
    vector<int> tree;
    int n;

    void add(int i) {
        for (i++; i <= n; i += i & (-i)) tree[i]++;
    }
    int query(int i) {
        int s = 0;
        for (i++; i > 0; i -= i & (-i)) s += tree[i];
        return s;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        n = sorted.size();
        tree.assign(n + 1, 0);

        int sz = nums.size();
        vector<int> res(sz);
        for (int i = sz - 1; i >= 0; i--) {
            int rank = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();
            res[i] = rank > 0 ? query(rank - 1) : 0;
            add(rank);
        }
        return res;
    }
};
