// Link: https://leetcode.com/problems/find-the-original-array-of-prefix-xor/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1) extra (excluding the output array)
// Approach: pref[i] = arr[0]^arr[1]^...^arr[i], so arr[0] = pref[0], and
// for i >= 1, arr[i] = pref[i] ^ pref[i-1] since xoring pref[i-1] cancels
// out every term except arr[i].
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> arr(n);
        arr[0] = pref[0];
        for (int i = 1; i < n; ++i)
            arr[i] = pref[i] ^ pref[i - 1];
        return arr;
    }
};
