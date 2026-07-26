// Link: https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n + k)
// SC: O(k)
// Approach: greedily always take the current largest available value.
// Sort nums ascending so the original largest values can be popped from
// the back; replaced values (ceil(x/3)) only ever shrink, so they're
// appended to a side list that stays sorted on its own — merging the two
// sorted sources (remaining original suffix vs. generated replacements)
// via a simple two-pointer comparison picks the true running maximum
// each of the k rounds.
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sc = 0;
        vector<int> arr;
        sort(nums.begin(), nums.end());
        int n = nums.size(), ind = -1, i = n - 1, ops = k;
        while (ops--) {
            if (i >= 0 && (ind == -1 || arr[ind] < nums[i])) {
                sc += nums[i];
                int newn = nums[i] / 3;
                if (nums[i] % 3)
                    newn++;
                arr.push_back(newn);
                i--;
                if (ind == -1)
                    ind++;
            } else {
                sc += arr[ind];
                int newn = arr[ind] / 3;
                if (arr[ind] % 3)
                    newn++;
                arr.push_back(newn);
                ind++;
            }
        }
        return sc;
    }
};
