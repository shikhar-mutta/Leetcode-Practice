// Link: https://leetcode.com/problems/distribute-elements-into-two-arrays-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: coordinate-compress values, use two Fenwick trees (one per
// array) to count how many existing elements in each array are strictly
// greater than the current value. Assign to the array with the larger
// greater-count; on a tie, assign to the shorter array (or arr1 if equal
// length), then update that array's BIT.
class Solution {
    vector<int> bit1, bit2;
    int sz;
    void update(vector<int>& bit, int i, int delta) {
        for (; i <= sz; i += i & (-i)) bit[i] += delta;
    }
    int query(vector<int>& bit, int i) {
        int s = 0;
        for (; i > 0; i -= i & (-i)) s += bit[i];
        return s;
    }
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        sz = sorted.size();
        bit1.assign(sz + 1, 0);
        bit2.assign(sz + 1, 0);
        auto rank = [&](int v) {
            return lower_bound(sorted.begin(), sorted.end(), v) - sorted.begin() + 1;
        };
        vector<int> arr1, arr2;
        int n = nums.size();
        arr1.push_back(nums[0]);
        update(bit1, rank(nums[0]), 1);
        arr2.push_back(nums[1]);
        update(bit2, rank(nums[1]), 1);
        for (int i = 2; i < n; i++) {
            int r = rank(nums[i]);
            int cnt1 = (int)arr1.size() - query(bit1, r);
            int cnt2 = (int)arr2.size() - query(bit2, r);
            bool toArr1;
            if (cnt1 > cnt2) toArr1 = true;
            else if (cnt2 > cnt1) toArr1 = false;
            else if (arr1.size() != arr2.size()) toArr1 = arr1.size() < arr2.size();
            else toArr1 = true;
            if (toArr1) { arr1.push_back(nums[i]); update(bit1, r, 1); }
            else { arr2.push_back(nums[i]); update(bit2, r, 1); }
        }
        for (int x : arr2) arr1.push_back(x);
        return arr1;
    }
};
