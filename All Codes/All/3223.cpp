// Link: https://leetcode.com/problems/minimum-length-of-string-after-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: For a character occurring x times, pairs of it (indices i,j,k
// with i<j<k and same char) let you delete both endpoints, so any count can
// be reduced down to 1 if odd, or 2 if even. Sum that minimal leftover count
// per distinct character.
class Solution {
public:
    int minimumLength(string s) {
        int arr[26] = {0};
        int out = 0;
        for (char c : s) arr[c-'a']++;
        for (int x : arr) if (x) out+= 2-(x%2);
        return out;
    }
};
