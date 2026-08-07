// Link: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n) for tokenizing
// Approach: track available "slots" for children; start with 1 slot (root),
// each node consumes a slot, non-null nodes add 2 slots; must end at exactly 0
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string tok;
        int slots = 1;
        while (getline(ss, tok, ',')) {
            if (slots <= 0) return false;
            slots--;
            if (tok != "#") slots += 2;
        }
        return slots == 0;
    }
};
