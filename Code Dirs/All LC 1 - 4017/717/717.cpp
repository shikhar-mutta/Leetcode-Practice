// Link: https://leetcode.com/problems/1-bit-and-2-bit-characters/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: scan left to right; a '1' bit always consumes 2 positions, a '0' consumes 1. Check if the final character consumed is the last bit and is a single '0'.
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, n = bits.size();
        while (i < n-1) {
            i += bits[i] == 1 ? 2 : 1;
        }
        return i == n-1;
    }
};
