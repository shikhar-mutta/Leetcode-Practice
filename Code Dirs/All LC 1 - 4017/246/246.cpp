// Link: https://leetcode.com/problems/strobogrammatic-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: two pointers from both ends; each pair of digits must be a valid strobogrammatic
// rotation pair (0-0, 1-1, 6-9, 8-8, 9-6)
class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> rot = {{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
        int l = 0, r = num.size() - 1;
        while (l <= r) {
            if (!rot.count(num[l]) || rot[num[l]] != num[r]) return false;
            l++; r--;
        }
        return true;
    }
};
