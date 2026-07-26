// Link: https://leetcode.com/problems/neighboring-bitwise-xor/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: a valid cyclic original array exists iff XOR of all derived
// values is 0 (each original bit gets XORed into derived exactly twice across
// the cycle, so they cancel out overall). n==1/n==2 are handled as direct
// special cases of that same rule. Note: `totalxor^derived[i] != derived[i]`
// relies on C++ operator precedence (!= binds tighter than ^), so it reduces
// to `totalxor ^ 0` = `totalxor` every iteration — equivalent to a single
// `if (totalxor) return false;` check, just repeated n times.
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        if(n == 1){
            return !derived[0];
        }
        if(n == 2){
            return !(derived[0]^derived[1]);
        }
        int totalxor=0;
        for(int i=0; i<n; i++){
            totalxor ^= derived[i];
        }

        for(int i=0; i<n; i++){
            if(totalxor^derived[i] != derived[i]) return false;
        }
        return true;
    }
};
