// Link: https://leetcode.com/problems/split-the-array-to-make-coprime-products/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N sqrt(maxVal)), SC: O(N)
// Approach: for each prime factor across all nums, record its last occurrence index. Scan left
// to right tracking the max "reach" (furthest last-occurrence among primes seen so far); a valid
// split exists right after index i iff reach == i (no shared prime factor crosses the boundary).
class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> lastIndex;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int p = 2; (long long)p * p <= x; p++) {
                if (x % p == 0) {
                    while (x % p == 0) x /= p;
                    lastIndex[p] = i;
                }
            }
            if (x > 1) lastIndex[x] = i;
        }

        int reach = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int p = 2; (long long)p * p <= x; p++) {
                if (x % p == 0) {
                    while (x % p == 0) x /= p;
                    reach = max(reach, lastIndex[p]);
                }
            }
            if (x > 1) reach = max(reach, lastIndex[x]);
            if (reach == i && i != n-1) return i;
        }
        return -1;
    }
};
