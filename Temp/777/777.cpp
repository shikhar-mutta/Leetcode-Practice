// Link: https://leetcode.com/problems/swap-adjacent-in-lr-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: the non-'X' subsequences of start and result must match (same letters in order); additionally L can only move left (its index in start >= its index in result) and R can only move right (its index in start <= its index in result).
class Solution {
public:
    bool canTransform(string start, string result) {
        int n = start.size();
        int i = 0, j = 0;
        while (i < n || j < n) {
            while (i < n && start[i] == 'X') i++;
            while (j < n && result[j] == 'X') j++;
            if (i == n && j == n) return true;
            if (i == n || j == n) return false;
            if (start[i] != result[j]) return false;
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;
            i++; j++;
        }
        return true;
    }
};
