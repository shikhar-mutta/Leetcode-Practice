// Link: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> cnt(k, 0);
        for (int x : arr) {
            int r = ((x % k) + k) % k;
            cnt[r]++;
        }
        if (cnt[0] % 2 != 0) return false;
        for (int r = 1; r <= k / 2; r++) {
            if (r == k - r) {
                if (cnt[r] % 2 != 0) return false;
            } else {
                if (cnt[r] != cnt[k-r]) return false;
            }
        }
        return true;
    }
};
