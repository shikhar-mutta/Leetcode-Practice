// Link: https://leetcode.com/problems/chalkboard-xor-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: Alice wins iff the total XOR is already 0 (Bob is forced to break it), or the array has even length (parity argument guarantees Alice can always force a win).
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int x = 0;
        for (int n : nums) x ^= n;
        return x == 0 || nums.size() % 2 == 0;
    }
};
